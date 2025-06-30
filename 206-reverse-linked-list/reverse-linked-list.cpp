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
    // T.C. = O(n) for pushing elements in stack + O(n) for replacing elements of LL with stack
    //        = O(2n)
    // S.C. = O(n) for stack
    ListNode* reverseList1(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;

        while(temp) {
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;
        while(temp) {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }

        return head;
    }
    
    ListNode* reverseList(ListNode* head) {
        // Brute Force Approach
        return reverseList1(head);
    }
};