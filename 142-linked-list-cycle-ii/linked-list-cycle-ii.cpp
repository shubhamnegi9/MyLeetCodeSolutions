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
    ListNode* detectCycleUsingBrute(ListNode *head) {

        // Empty node and single node cannot make cycle
        if(head == NULL || head->next == NULL) {
            return NULL;
        }

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

    // Using Slow and Fast Pointers
    ListNode* detectCycleUsingOptimal(ListNode* head) {
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
                break;
        }

        // In case while loop is not break due to slow==fast, 
        // it means that there is no cycle in linked list.
        if(slow != fast)
            return NULL;
        
        // At this point, it is confirmed that cycle must be present.
        // Initialize pointer p and move slow and p pointers by one step.
        // The point where they both meet must be the beginning node of cycle.
        ListNode* p = head;
        while(p != slow) {
            p = p->next;
            slow = slow->next;
        }
        return p;    // or return slow;
    }

    ListNode *detectCycle(ListNode *head) {
        // Using Brute Force
        // return detectCycleUsingBrute(head);

        // Using Optimal Approach
        return detectCycleUsingOptimal(head);
    }
};