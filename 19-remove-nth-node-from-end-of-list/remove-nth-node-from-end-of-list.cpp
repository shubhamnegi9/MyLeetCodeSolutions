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
    /*
        Using Two Passes
        Time Complexity = O(len) + O(len-n)     
                        = O(2*len) in worst case
        Space Complexity = O(1)                
        len = length of Linked List, n = nth node to be deleted from end 
    */
    ListNode* removeUsingTwoPass(ListNode* head, int n) {
        // For tracking previous node
        ListNode* prev = NULL;
        ListNode* curr = head;
        int sz = 0;

        // Finding the size of LL 
        while(curr) {
            sz+=1;
            curr = curr->next;
        }

        // Node to remove from front/beginning
        int nodeToRemove = sz - n;
        // For tracking current node 
        int currNode = 0;
        curr = head;

        if(nodeToRemove == 0) {
            // This is the first node in LL to be removed
            // Simply move head to next node to remove it
            ListNode* newHead = head->next;
            delete (head);  // Delete the memory allocated to head node
            return newHead;
        }

        // Iterate till the end of LL
        while(curr) {
            if(currNode == nodeToRemove) {
                // Link prev node to next node of curr to remove curr node
                ListNode* temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete(temp);   // Delete the memory allocated to curr node
                break;
            }
            else {
                currNode++;
                // Make curr node as prev node before moving to next
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }

    /*
        Using One Pass
        T.C. = O(n) for the fast pointer
        S.C. = O(1)
    */
    ListNode* removeUsingOnePass(ListNode* head, int n) {
        // Fast and Slow Pointers
        ListNode* fast = head;
        ListNode* slow = head;

        // Moving fast pointer to 'n' nodes ahead 
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If fast pointer reaches after end of LL
        // (in case n = length of LL)
        if(fast == NULL) {
            // Node to be removed from end is the first node in the LL
            // Move head to next node to remove it and return new head
            ListNode* newHead = head->next;
            delete(head);
            return newHead;
        }

        // Iterate until fast pointer is pointing to last node
        while(fast->next) {
            // Move fast and slow pointer simultaneously
            fast = fast->next;
            slow = slow->next;
        }

        // slow pointer is now pointing to one node before the node to be deleted from end
        ListNode* nodeToDelete = slow->next;
        // Linking to node which is next to the node to be deleted 
        slow->next = slow->next->next;
        delete(nodeToDelete);

        return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // return removeUsingTwoPass(head, n);

        return removeUsingOnePass(head, n);
    }
};