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
    // T.C. = O(n1+n2)
    // S.C. = O(n1) or O(n2), where n1 = size of fist LL, n2 = size of second LL
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        // Edge Case
        if(headA == NULL || headB == NULL)
            return NULL;

        ListNode* temp = headA;

        unordered_map<ListNode*, int> mpp;

        while(temp) {
            mpp[temp] = 1;
            temp = temp->next;
        }

        temp = headB;
        while(temp) {
            if(mpp.find(temp) != mpp.end()) {
                return temp;
            }
            temp = temp->next;
        }

        return NULL;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Brute Force Approach
        return getIntersectionNode1(headA, headB);
    }
};