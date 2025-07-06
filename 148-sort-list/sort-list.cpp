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
    // T.C. = O(n) for adding all element in array + O(nlogn) for sorting array + O(n) for replacing the data back in linked list
    // S.C. = O(n) for array
    ListNode* sortList1(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;

        while(temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        sort(arr.begin(), arr.end());

        temp = head;
        int i = 0;
        while(temp) {
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }

        return head;
    }
    
    ListNode* sortList(ListNode* head) {
        // Brute Force Approach
        return sortList1(head);
    }
};