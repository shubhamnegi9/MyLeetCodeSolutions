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
    // T.C. = O(len) + O(len-n) = 2*O(len) if n=1
    // S.C. = O(1)
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
    
    // Optimal Approach
    // T.C. = O(n) + O(len-n) = O(len)
    // S.C. = O(1)
    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast pointer by n steps
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Edge Case
        if(fast==NULL) {
            // Remove head node
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Move slow and fast pointers by 1 step until fast pointer reaches at last node
        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // At this point, slow pointer will be pointing to previous node of the node to be removed
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return head;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Brute Force Approach
        // return removeNthFromEnd1(head, n);

        // Optimal Approach
        return removeNthFromEnd2(head, n);
    }
};