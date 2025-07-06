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
    // Brute Force Approach
    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0;

        while(temp != NULL) {
            count++;
            temp = temp->next;
        }

        // Edge Case
        if(n == count) {
            // Remove node at head 
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        int res = count-n;
        temp = head;
        while(temp != NULL) {
            // First reduce res then check for (res==0)
            res--;
            if(res == 0) {
                break;
            }
            temp = temp->next;
        }

        // At this point, temp will be pointing to previous node of the node to be removed
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
        return head;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Brute Force Approach
        return removeNthFromEnd1(head, n);
    }
};