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
    // Brute Force Approach
    // T.C. = O(n) * O(2*logn) for fetching and inserting in ordered map
    //      = O(n) * O(2) for fetching and inserting in unordered map
    // S.C. = O(n) for map
    ListNode *detectCycle1(ListNode *head) {
        ListNode* temp = head;
        unordered_map<ListNode*, int> mpp;

        while(temp) {
            if(mpp.find(temp) != mpp.end()) {
                return temp;
            } 

            mpp[temp] = 1;
            temp = temp->next;
        }

        return NULL;
    }

    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(1)
    ListNode *detectCycle2(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                slow = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;    // OR   return fast;
            }
        }

        return NULL;
    }
    
    ListNode *detectCycle(ListNode *head) {
        // Brute Force Approach
        // return detectCycle1(head);

        // Optimal Approach
        return detectCycle2(head);
    }
};