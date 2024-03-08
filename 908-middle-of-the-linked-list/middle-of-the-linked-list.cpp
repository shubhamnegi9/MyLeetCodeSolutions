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
    // Using Brute Force
    // T.C. = O(2n), S.C. = O(1)
    ListNode* middleNodeUsingBrute(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            len++;
            temp = temp -> next;
        }

        int mid = len/2;
        temp = head;
        int i = 0;
        while(temp != NULL) {
            if(i == mid)
                head = temp;
            i++;
            temp = temp -> next;
        } 

        return head;
    }

    // Using Slow and Fast Pointer Approach
    ListNode* middleNodeUsingOptimal(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow-> next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* middleNode(ListNode* head) {
        // Using Brute Force
        // return middleNodeUsingBrute(head);

        // Using Optimal Approach
        return middleNodeUsingOptimal(head);
    }
};