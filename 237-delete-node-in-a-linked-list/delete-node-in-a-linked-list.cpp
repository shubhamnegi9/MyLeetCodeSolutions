/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // Making current node value as next node value
        node->val = node->next->val;    

        // Removing next node from Linked List
        node->next = node->next->next;
    }
};