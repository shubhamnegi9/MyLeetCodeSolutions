/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        
        // Base Case
        if(head == NULL || head -> next == NULL)
            return head;
        
        // Gives the largest node to the right of current head node
        ListNode* nextNode = removeNodes(head->next);
        
        if(head-> val < nextNode -> val) {
            // Remove current head node and return nextNode 
            delete head;
            return nextNode;
        }
        
        // Link current head node's next to nextNode and return it
        head->next = nextNode;
        return head;   
    }
};