/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n) + O(n) = O(2n)
    // S.C. = O(n) for map + O(n) for returning cloned linked list = O(2n)
    Node* copyRandomList1(Node* head) {
        Node* temp = head;
        unordered_map<Node*, Node*> mpp;

        // Creating copy nodes and mapping of original and copied nodes in hashmap
        while(temp != NULL) {
            Node* copyNode = new Node(temp->val);
            mpp[temp] = copyNode;
            temp = temp->next;
        }

        // Linking next and random pointers of coped list
        temp = head;
        while(temp != NULL) {
            Node* copyNode = mpp[temp];
            copyNode->next = mpp[temp->next];
            copyNode->random = mpp[temp->random];
            temp = temp->next;
        }

        return mpp[head];
    }

    void insertCopyNodes(Node* head) {
        Node* temp = head;

        while(temp != NULL) {
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;    // Move temp by 2 steps to point to next original node
        }
    }

    void connectRandomPointers(Node* head) {
        Node* temp = head;

        while(temp != NULL) {
            Node* copyNode = temp->next;
            if(temp->random != NULL)
                copyNode->random = temp->random->next;
            else
                copyNode->random = nullptr;
            temp = temp->next->next;    // Move temp by 2 steps to point to next original node
        }
    }

    Node* getDeepCopyList(Node* head) {
        Node* temp = head;
        Node* dNode = new Node(-1);
        Node* res = dNode;

        while(temp != NULL) {
            // Linking next pointers of copied list
            res->next = temp->next;
            res = res->next;

            // Linking next pointers of original list
            temp->next = temp->next->next;
            temp = temp->next;
        }

        return dNode->next;
    }

    // Optimal Approach
    // T.C. = O(n) for each of 3 steps = O(3n)
    // S.C. = O(n) for returning cloned linked list = O(2n)
    Node* copyRandomList2(Node* head) {
        // Step 1: Insert the copy nodes in between the given original nodes
        insertCopyNodes(head);

        // Step 2: Connect the random pointers of copied nodes 
        connectRandomPointers(head);

        // Step 3: Connect the next pointers of copied nodes and return deep copy list
        return getDeepCopyList(head);
    }
    
    Node* copyRandomList(Node* head) {
        // Brute Force Approach
        return copyRandomList1(head);

        // Optimal Approach
        // return copyRandomList2(head);
    }
};