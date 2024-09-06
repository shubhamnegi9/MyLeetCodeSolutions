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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        // Adding elements to unordered set for quick access
        unordered_set<int> st(nums.begin(), nums.end());
        
        // Keep moving head to next node until it is not present in set
        // Also check for (head != NULL) in case all the elements are present in set
        while(head != NULL && st.find(head->val) != st.end()) {
            ListNode* temp = head;  // Storing in temp node to delete it
            head = head->next;
            delete(temp);           // Deleting hanging node
        }
            
        ListNode* curr = head;      // Curr will start from new head node
        while(curr && curr->next) {
            if(st.find(curr->next->val) != st.end()) {
                ListNode* temp = curr->next;        // Storing in temp node to delete it
                curr->next = curr->next->next;
                delete(temp);       // Deleting hanging node
            }
            else {
                curr = curr->next;
            }
        }
        
        return head;
    }
};