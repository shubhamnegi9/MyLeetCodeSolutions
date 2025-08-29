class Node {
    public:
    int key, value, cnt;
    Node* prev;
    Node* next;
    Node(int _key, int _value) {
        key = _key;
        value = _value;
        cnt = 1;
    }
};

class List {
    public:
    Node* head;
    Node* tail;
    int size;

    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        size = 0;

        head->next = tail;
        tail->prev = head;
    }

    void insertNodeAfterHead(Node* newNode) {
        Node* nodeAfterHead = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = nodeAfterHead;
        nodeAfterHead->prev = newNode;
        size++;
    }

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        if(prevNode)
            prevNode->next = nextNode;
        if(nextNode)
            nextNode->prev = prevNode;
        size--;    
    }
};

class LFUCache {
public:
    map<int, List*> freqListMap;
    map<int, Node*> keyNodeMap;
    int cacheSize, maxCapacity, minFreq;

    LFUCache(int capacity) {
        maxCapacity = capacity;
        freqListMap.clear();
        keyNodeMap.clear();
        cacheSize = 0;
        minFreq = 0;
    }

    void updateFreqListMap(Node* node) {
        keyNodeMap.erase(node->key);        // Removing node from keyNodeMap (Do this before removing from freqListMap)
        freqListMap[node->cnt]->deleteNode(node);   // Removing node from freqListMap at frequency node->cnt
        // If list at minFreq key in freqListMap is empty
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++;
        }

         // Adding node in freqListMap at frequency node->cnt+1
        List* nextFreqList = new List();
        if(freqListMap.find(node->cnt+1) != freqListMap.end()) {
            nextFreqList =  freqListMap[node->cnt+1];
        }
        node->cnt+=1;
        nextFreqList->insertNodeAfterHead(node);
        freqListMap[node->cnt] = nextFreqList;
        keyNodeMap[node->key] = node;       // Adding node from keyNodeMap
    }
    
    int get(int key) {
        if(keyNodeMap.find(key) == keyNodeMap.end()) {      // Key not found in map
            return -1;
        }

        Node* node = keyNodeMap[key];
        updateFreqListMap(node);        // Update in freqListMap and keyNodeMap
        return node->value; 
    }
    
    void put(int key, int value) {
        // Edge Case
        if(maxCapacity == 0) {
            return;
        }

        if(keyNodeMap.find(key) != keyNodeMap.end()) {     // Key found in map
            Node* node = keyNodeMap[key];
            node->value = value;        // Update node value
            updateFreqListMap(node);    // Update in freqListMap and keyNodeMap

        } else {
            if(cacheSize == maxCapacity) {
                List* minFreqList = freqListMap[minFreq];
                keyNodeMap.erase(minFreqList->tail->prev->key);     // Removing last node from keyNodeMap (Do this before removing from freqListMap)
                freqListMap[minFreq]->deleteNode(minFreqList->tail->prev);   // Removing last node from freqListMap
                cacheSize--;
            }

            cacheSize++;
            minFreq = 1;
            List* newList = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()) {
                newList = freqListMap[minFreq];
            }
            Node* newNode = new Node(key, value);
            newList->insertNodeAfterHead(newNode);      // Adding new node in newList
            keyNodeMap[key] = newNode;                  // Adding new node in keyNodeMap
            freqListMap[minFreq] = newList;             // Adding newList in freqListMap
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */