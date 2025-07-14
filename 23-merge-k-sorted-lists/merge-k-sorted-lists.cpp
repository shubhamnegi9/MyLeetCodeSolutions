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

    ListNode* arrayToLinkedList(vector<int>& arr) {
        ListNode* head = new ListNode(arr[0]);
        ListNode* temp = head;

        for(int i = 1; i < arr.size(); i++) {
            ListNode* newNode = new ListNode(arr[i]);
            temp->next = newNode;
            temp = newNode;
        }

        return head;
    }

    // Brute Force Approach
    // T.C. = O(K*N) + O(MlogM) + O(M), M = K*N
    // S.C. = O(M) for array + O(M) for merged LL
    ListNode* mergeKLists1(vector<ListNode*>& lists) {
        vector<int> arr;

        for(int i = 0; i < lists.size(); i++) {         // O(K*N)
            ListNode* temp = lists[i];      // Head of the ith linked list

            while(temp != NULL) {
                arr.push_back(temp->val);
                temp = temp->next;
            }
        }
        
        // Egde Case
        // In case arr is empty and inside arrayToLinkedList(), we are accessing arr[0] which will give NPE
        if(arr.empty()) {
            return NULL;
        }

        sort(arr.begin(), arr.end());       // O(MlogM), M = K*N

        return arrayToLinkedList(arr);      // O(M), M = K*N
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Brute Force Approach
        return mergeKLists1(lists);
    }
};