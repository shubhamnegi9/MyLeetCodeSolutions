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
    // T.C. = O(n) * O(1) for unordered map
    // S.C. = O(n) for map
    bool hasCycle1(ListNode *head) {
        ListNode* temp = head;
        unordered_map<ListNode*, int> mpp;

        while(temp != NULL) {
            if(mpp.find(temp) != mpp.end()) {
                return true;
            } 

            mpp[temp] = 1;
            temp = temp->next;
        }

        return false;
    }
    
    bool hasCycle(ListNode *head) {
        // Brute Force Approach
        return hasCycle1(head);
    }
};