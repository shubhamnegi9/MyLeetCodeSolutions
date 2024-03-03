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
        // For tracking previous node
        ListNode* prev = NULL;
        ListNode* curr = head;
        int sz = 0;

        // Finding the size of LL 
        while(curr) {
            sz+=1;
            curr = curr->next;
        }

        // Node to remove from front/beginning
        int nodeToRemove = sz - n;
        // For tracking current node 
        int currNode = 0;
        curr = head;

        if(nodeToRemove == 0) {
            // This is the first node in LL to be removed
            // Simply move head to next node to remove it
            ListNode* newHead = head->next;
            delete (head);  // Delete the memory allocated to head node
            return newHead;
        }

        // Iterate till the end of LL
        while(curr) {
            if(currNode == nodeToRemove) {
                // Link prev node to next node of curr to remove curr node
                ListNode* temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete(temp);   // Delete the memory allocated to curr node
                break;
            }
            else {
                currNode++;
                // Make curr node as prev node before moving to next
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};