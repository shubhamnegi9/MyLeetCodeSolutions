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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int carry = 0;

        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;

        // Traverse until t1 or t2 is not NULL
        while(t1 != NULL || t2 != NULL) {
            int sum = carry;

            if(t1 != NULL)
                sum += t1->val;    // Add value at t1 to sum only if t1 != NULL
            if(t2 != NULL)
                sum += t2->val;    // Add value at t2 to sum only if t2 != NULL
            
            ListNode* newNode = new ListNode(sum%10);   // Value of new node will be (sum%10)
            carry = sum/10;     // Can also write carry = 1;

            curr->next = newNode;
            curr = curr->next;      // OR curr = newNode;

            if(t1 != NULL)
                t1 = t1->next;      // Movet t1 only if t1 != NULL
            if(t2 != NULL)
                t2 = t2->next;      // Movet t2 only if t2 != NULL
        }

        if(carry == 1) {
            ListNode* newNode = new ListNode(1);
            curr->next = newNode;
            // curr = curr->next;       // Not required here
        }

        return (dummyNode->next);       // Return (dummyNode->next) as head of sum list
    }
};