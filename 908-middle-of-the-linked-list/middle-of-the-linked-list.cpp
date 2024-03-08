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

    ListNode* middleNode(ListNode* head) {
        // Using Brute Force
        return middleNodeUsingBrute(head);
    }
};