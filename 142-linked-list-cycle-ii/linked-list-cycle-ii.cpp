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
        // Set for storing the nodes traversed so far
        set<ListNode*> s;

        while(head) {
            // If node found in set, then we have reached to same node again.
            // This node is begining of cycle.
            if(s.find(head) != s.end()) {
                return head;
            }
            // Insert current node in set
            s.insert(head);
            head = head->next;
        }

        // No cycle is present 
        return NULL;
    }

    ListNode *detectCycle(ListNode *head) {
        // Using Brute Force
        return detectCycleUsingBrute(head);
    }
};