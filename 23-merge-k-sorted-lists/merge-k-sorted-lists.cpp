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

    ListNode* mergeTwoLinkedLists(ListNode* list1, ListNode* list2) {   // O(n1+n2)
        ListNode* t1 = list1;   
        ListNode* t2 = list2;

        ListNode* dNode = new ListNode(-1);
        ListNode* temp = dNode;

        while(t1 != NULL && t2 != NULL) {
            if(t1->val < t2->val) {
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            } else {
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }

        if(t1 != NULL)
            temp->next = t1;
        if(t2 != NULL)
            temp->next = t2;
        
        return dNode->next;
    }


    // Better Approach (Space optimized approach)
    // T.C. = O(n1+n2) + O(n1+n2+n3) + ...
    //      = O(2N) + O(3N) + ...
    //      = O(N) + O(2n) + O(3N) + ...
    //      = O(n*(k*(k+1))/2)
    // S.C. = O(1)
    ListNode* mergeKLists2(vector<ListNode*>& lists) {
        // Egde Case
        if(lists.empty())
            return NULL;

        ListNode* head = lists[0];
        for(int i = 1; i < lists.size(); i++) {
            ListNode* temp = lists[i];
            head = mergeTwoLinkedLists(head, temp);
        }
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Brute Force Approach
        // return mergeKLists1(lists);

        // Better Approach (Space optimized approach)
        return mergeKLists2(lists);
    }
};