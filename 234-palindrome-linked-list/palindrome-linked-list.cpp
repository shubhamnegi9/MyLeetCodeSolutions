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
            if(temp->val != st.top()) {     // Not a palindrome
                return false;
            }
            st.pop();
            temp = temp->next;
        }

        return true;
    }

    ListNode* reverseListIterative(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }

    ListNode* reverseListRecursive(ListNode* head) {
        // Base Case
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* newHead = reverseListRecursive(head);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    } 

    // Optimal Approach
    // T.C. = O(n/2) for finding the first and second half + O(n/2) for reversing second half
    //        + O(n/2) for checking palindrome + O(n/2) for reversing before returning
    //      = O(2n)
    // S.C. = O(1)         
    bool isPalindrome2(ListNode* head) {

        // Edge Case
        if(head == NULL || head->next == NULL)
            return true;        // Empty and single length linked list are palindromes

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverseListRecursive(slow->next);

        ListNode* first = head;
        ListNode* second = newHead;

        while(second != NULL) {
            if(first->val != second->val) {     // Not a palindrome
                // reverse the second half before returning false
                reverseListRecursive(slow->next);
                return false;
            }

            first = first->next;
            second = second->next;
        }
        // reverse the second half before returning true
        reverseListRecursive(slow->next);
        return true;
    }
    
    bool isPalindrome(ListNode* head) {
        // Brute Force Approach
        return isPalindrome1(head);

        // Optimal Approach
        return isPalindrome2(head);
    }
};