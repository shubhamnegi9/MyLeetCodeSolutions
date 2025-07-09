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

    ListNode* findCollisionPoint(ListNode *t1, ListNode *t2, int d) {
        while(d) {
            d--;
            t2 = t2->next;
        }

        while(t1 != t2) {
            t1 = t1->next;
            t2 = t2->next;
        }

        return t1;      // OR  return t2;
    }
    
    // Better Approach
    // T.C. = O(n1) + O(n2) + O(n2-n1) + O(n1) = O(n1+2*n2)
    // S.C. = O(1)
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        // Edge Case
        if(headA == NULL || headB == NULL)
            return NULL;
        
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int n1 = 0, n2 = 0;

        while(tempA) {
            n1++;
            tempA = tempA->next;
        }

        while(tempB) {
            n2++;
            tempB = tempB->next;
        }

        if(n1 < n2) {
            return findCollisionPoint(headA, headB, n2-n1);
        } else {
            return findCollisionPoint(headB, headA, n1-n2);
        }
    }

    // Optimal Approach
    // T.C. = O(n1+n2)
    // S.C. = O(1)
    ListNode *getIntersectionNode3(ListNode *headA, ListNode *headB) {
        // Edge Case
        if(headA == NULL || headB == NULL)
            return NULL;
        
        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while(t1 != t2) {
            t1 = t1->next;
            t2 = t2->next;

            if(t1 == t2)
                return t1;      // OR  return t2;
            
            if(t1==NULL)                
                t1 = headB;
            if(t2==NULL)
                t2 = headA;
        }

        return t1;      // OR  return t2;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Brute Force Approach
        // return getIntersectionNode1(headA, headB);

        // Better Approach
        // return getIntersectionNode2(headA, headB);

        // Optimal Approach
        return getIntersectionNode3(headA, headB);
    }
};