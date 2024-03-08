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
    // T.C. = O(n), S.C. = O(n)
    bool hasCycleUsingBrute(ListNode *head) {

        // Empty node and single node cannot make cycle
        if(head == NULL || head->next == NULL) {
            return false;
        }

        // Set for storing the nodes traversed so far
        set<ListNode*> s;

        while(head) {
            // If node found in set, then we have reached to same node again.
            // This node is begining of cycle.
            if(s.find(head) != s.end()) {
                return true;
            }
            // Insert current node in set
            s.insert(head);
            head = head->next;
        }

        // No cycle is present 
        return false;
    }

    // Using Slow and Fast Pointers
    bool hasCycleUsingOptimal(ListNode* head) {
        // Empty node and single node cannot make cycle
        if(head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            // Cycle is detected in linked list
            if(slow == fast)
                return true;
        }

        // In case while loop is not returned due to slow==fast, 
        // it means that there is no cycle in linked list.
        return false;
    }

    bool hasCycle(ListNode *head) {
        // Using Brute Force
        // return hasCycleUsingBrute(head);

        // Using Optimal Approach
        return hasCycleUsingOptimal(head);

    }
};