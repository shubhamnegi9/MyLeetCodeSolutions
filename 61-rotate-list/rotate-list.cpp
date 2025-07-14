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
    ListNode* findLastNode(ListNode* head, int target) {
        int cnt = 1;
        ListNode* temp = head;

        while(temp) {
            if(cnt == target) {
                return temp;
            }
            cnt++;
            temp = temp->next;
        }

        return temp;
    }

    // T.C. = O(n) for traversing to tail node + O(n) for finding last node of rotated linked list in worst case  = O(2n)
    // S.C. = O(1)
    ListNode* rotateRight(ListNode* head, int k) {
        // Edge Case
        if(head == NULL || k == 0) 
            return head;
        
        ListNode* tail = head;
        int len = 1;

        // Traverse until tail points to last node
        while(tail->next != NULL) {
            tail = tail->next;
            len++;
        }

        // If length of linked list is multiple of k, return head of linked list
        if(k % len == 0)
            return head;
        
        k = k % len;

        // Make tail point to head of given linked list
        tail->next = head;

        ListNode* newLastNode = findLastNode(head, len-k);  // Last node of rotated linked list
        head = newLastNode->next;
        newLastNode->next = NULL;
        return head;
    }
};