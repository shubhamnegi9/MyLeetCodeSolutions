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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        // Only one node is present in LL
        // Remove the node by making head = NULL and return head
        if(head->next == NULL) {
            head = NULL;
            return head;
        }
        int sz = 1;
        // Finding the size of LL 
        while(curr->next) {
            sz+=1;
            curr = curr->next;
        }
        // Node to remove from front/beginning
        int nodeToRemove = sz - n;
        // For tracking current node 
        int currNode = 0;
        curr = head;
        // Iterate till the end of LL
        while(curr) {
            if(currNode == nodeToRemove) {
                if(prev != NULL) {
                    // Link prev node to next node of curr to remove curr node
                    prev->next = curr->next;
                }
                else {
                    // This is the first node in LL to be removed
                    // Simply move head to next node to remove it
                    head = head->next;
                }
            }
            currNode++;
            // Make curr node as prev node before moving to next
            prev = curr;
            curr = curr->next;
        }

        return head;
    }
};