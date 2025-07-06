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
    // T.C. = O(n1) + O(n2) + O(nlogn) + O(n), n1 = size of list1, n2 = size of list2, n = n1+n2
    // S.C. = O(n) for array + O(n) for merged linked list
    ListNode* mergeTwoLists1(ListNode* list1, ListNode* list2) {
        vector<int> arr;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        // Edge Cases
        if(temp1 == NULL)
            return temp2;
        if(temp2 == NULL)
            return temp1;
        if(temp1 == NULL && temp2 == NULL)
            return NULL;

        // Step 1: Push elements of list1 and list2 into arr
        while(temp1 != NULL) {
            arr.push_back(temp1->val);
            temp1 = temp1->next;
        }

        while(temp2 != NULL) {
            arr.push_back(temp2->val);
            temp2 = temp2->next;
        }

        // Step 2: Sort array
        sort(arr.begin(), arr.end());

        // Step 3: Convert sorted array into linked list
        ListNode* head = new ListNode(arr[0]);
        ListNode* temp = head;
        for(int i = 1; i < arr.size(); i++) {
            ListNode* newNode = new ListNode(arr[i]);
            temp->next = newNode;
            temp = temp->next;
        }

        return head;
    }

    // Optimal Approach
    // T.C. = O(n1+n2), n1 = size of list1, n2 = size of list2
    // S.C. = O(1)
    ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1;
        ListNode* t2 = list2;

        // Edge Cases
        if(t1 == NULL)
            return t2;
        if(t2 == NULL)
            return t1;
        if(t1 == NULL && t2 == NULL)
            return NULL;

        // Creating dummy node for changing the links
        ListNode* dNode = new ListNode(-1);
        ListNode* temp = dNode;

        while(t1 != NULL && t2 != NULL) {
            if(t1->val < t2->val) {
                temp->next = t1;
                temp = t1;  // OR temp = temp->next;
                t1 = t1->next;
            }
            else {
                temp->next = t2;
                temp = t2;  // OR temp = temp->next;
                t2 = t2->next;
            }
        }

        if(t1 != NULL) 
            temp->next = t1;
        else
            temp->next = t2;
        
        return dNode->next;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Brute Force Approach
        // return mergeTwoLists1(list1, list2);

        // Optimal Approach
        return mergeTwoLists2(list1, list2);
    }
};