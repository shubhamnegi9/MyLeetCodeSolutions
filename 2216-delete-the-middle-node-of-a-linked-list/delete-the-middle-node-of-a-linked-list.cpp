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
    // T.C. = O(n) for finding the length of LL + O(n/2) for traversing till middle node
    //      = O(n) + O(n/2)
    // S.C. = O(1)
    ListNode* deleteMiddle1(ListNode* head) {
        ListNode* temp = head;
        int N = 0;

        // Edge Case
        if(head == NULL || head->next == NULL)
            return NULL;

        while(temp) {
            N++;
            temp = temp->next;
        }

        int res = N/2;  // Middle node position
        temp = head;

        while(res) {
            // First reduce res value then check for res == 0
            res--;

            if(res == 0) {
                break;
            }

            temp = temp->next;
        }

        // At this point, temp will be pointing to one node before the middle of linked list
        ListNode* middle = temp->next;
        temp->next = temp->next->next;
        delete middle;
        return head;
    }

    // Optimal Approach
    // T.C. = O(n/2) for moving fast pointer 
    // S.C. = O(1)
    ListNode* deleteMiddle2(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        // Edge Case
        if(head == NULL || head->next == NULL)
            return NULL;

        // Intially move fast pointer by 2 steps and skip moving of slow pointer
        fast = fast->next->next;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }   

        // At this point, slow pointer will be pointing to one node before the middle of linked list
        ListNode* middle = slow->next;
        slow->next = slow->next->next;
        delete middle;
        return head;
    }
    
    ListNode* deleteMiddle(ListNode* head) {
        // Brute Force Approach
        // return deleteMiddle1(head);

        // Optimal Approach
        return deleteMiddle2(head);
    }
};