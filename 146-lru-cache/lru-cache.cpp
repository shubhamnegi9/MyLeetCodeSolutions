class LRUCache {
public:
    class Node {
        public:
        int key, val;
        Node* next;
        Node* prev;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
            next = nullptr;
            prev = nullptr;
        }
    };

    int capacity;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> mpp;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        head->prev = NULL;
        tail->prev = head;
        tail->next = NULL;
        mpp.clear();
    }

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        if(prevNode != NULL)
            prevNode->next = nextNode;
        if(nextNode != NULL)
            nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* newNode) {
        Node* nodeAfterHead = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = nodeAfterHead;
        nodeAfterHead->prev = newNode;
    }
    
    int get(int key) {
        // Key not found in map
        if(mpp.find(key) == mpp.end())
            return -1;
        

        Node* temp = mpp[key];
        // Move most recently used node at the beginning after head
        deleteNode(temp);
        insertAfterHead(temp);

        return temp->val;
    }
    
    void put(int key, int value) {
        // Key found in map. Update existing key
        if(mpp.find(key) != mpp.end()) {
            Node* temp = mpp[key];
            temp->val = value;      // Updating value in node
            mpp[key] = temp;        // Updating node in map

            // Move most recently used node at the beginning after head
            deleteNode(temp);
            insertAfterHead(temp);
        } else {
            // Key not found in map. Insert as a new node
            if(mpp.size() == capacity) {
                // Remove least recently used (LRU) last node before tail
                Node* temp = tail->prev;
                deleteNode(temp);           // Removing last node before tail
                mpp.erase(temp->key);       // Removing its entry from map
            } 
            
            // Insert new node at the beginning after head
            Node* newNode = new Node(key, value);
            insertAfterHead(newNode);
            mpp[key] = newNode;           // Inserting node in map
            
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */