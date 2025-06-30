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

    // Optimal Approach (Iterative Way)
    // T.C. = O(n)
    // S.C. = O(1)
    ListNode* reverseList2(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;   
        }

        return prev;    // prev will be head of reversed LL
    }

    // Optimal Approach (Recursive Way)
    // T.C. = O(n) for n recursive calls
    // S.C. = O(n) recursive stack space
    ListNode* reverseList3(ListNode* head) {
        // Base Case
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* newHead = reverseList3(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
    
    ListNode* reverseList(ListNode* head) {
        // Brute Force Approach
        // return reverseList1(head);

        // Optimal Approach (Iterative Way)
        // return reverseList2(head);

        // Optimal Approach (Recursive Way)
        return reverseList3(head);
    }
};