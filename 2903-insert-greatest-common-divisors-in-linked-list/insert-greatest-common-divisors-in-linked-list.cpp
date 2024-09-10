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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == NULL)
            return head;
        
        ListNode* curr = head;
        
        while(curr->next != NULL) {
            int gcd = __gcd(curr->val, curr->next->val);
            ListNode* newNode = new ListNode(gcd);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = curr->next->next;
        }
        
        return head;
    }
};