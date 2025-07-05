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
    // T.C. = O(2n)
    // S.C. = O(n) for stack
    bool isPalindrome1(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;

        while(temp != NULL) {
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;
        while(temp != NULL) {
            if(temp->val != st.top()) {
                return false;
            }
            st.pop();
            temp = temp->next;
        }

        return true;
    }
    
    bool isPalindrome(ListNode* head) {
        // Brute Force Approach
        return isPalindrome1(head);
    }
};