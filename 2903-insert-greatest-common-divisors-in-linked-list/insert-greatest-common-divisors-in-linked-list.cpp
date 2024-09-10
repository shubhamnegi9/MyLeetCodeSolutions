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
    
    ListNode* insertGreatestCommonDivisorsIterative(ListNode* head) {
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
    
    // Recursive Approach
    ListNode* insertGreatestCommonDivisorsRecursive(ListNode* head) {
        // Base Case
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* temp = insertGreatestCommonDivisorsRecursive(head->next);
        int gcd = __gcd(head->val, head->next->val);
        ListNode* newNode = new ListNode(gcd);
        newNode->next = temp;
        head->next = newNode;
        
        return head;
    }
    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // Iterative Approach
        // return insertGreatestCommonDivisorsIterative(head);
        
        // Recursive Approach
        return insertGreatestCommonDivisorsRecursive(head);
    }
};