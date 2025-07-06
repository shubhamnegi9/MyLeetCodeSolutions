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
        // Edge Case
        if(head == NULL || head->next == NULL)
            return head;

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

    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;    // Required modification. Start fast from head->next

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1;
        ListNode* t2 = list2;

        // Edge Cases
        if(t1 == NULL)
            return t2;
        if(t2 == NULL)
            return t1;
        if(t1 == NULL && t2 == NULL) 
            return NULL;
        
        ListNode* dNode = new ListNode(-1);
        ListNode* temp = dNode;

        while(t1 != NULL && t2 != NULL) {
            if(t1->val < t2->val) {
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else {
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }

        if(t1 != NULL)
            temp->next = t1;
        else
            temp->next = t2;
        
        return dNode->next;
    }

    // Optimal Approach
    // T.C. = O(logn*(n+n/2))
    // S.C. = O(1)
    ListNode* sortList2(ListNode* head) {
        // Base Case of recursion
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* middle = findMiddle(head);
        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;

        // Make middle->next = NULL to separate left and right half
        middle->next = NULL;

        leftHead = sortList2(leftHead);
        rightHead = sortList2(rightHead);

        return mergeTwoLists(leftHead, rightHead); 
    }
    
    ListNode* sortList(ListNode* head) {
        // Brute Force Approach
        // return sortList1(head);

        // Optimal Approach
        return sortList2(head);
    }
};