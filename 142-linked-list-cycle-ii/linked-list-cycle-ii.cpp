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
    // Using Brute Force
    ListNode* detectCycleUsingBrute(ListNode *head) {
        set<ListNode*> s;
        int begin = -1;
        while(head) {
            if(s.find(head) != s.end()) {
                return head;
            }
            s.insert(head);
            head = head->next;
        }

        return NULL;
    }

    ListNode *detectCycle(ListNode *head) {
        // Using Brute Force
        return detectCycleUsingBrute(head);
    }
};