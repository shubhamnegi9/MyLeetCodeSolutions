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
    // T.C. = O(n) + O(n/2)
    // S.C. = O(1)
    ListNode* middleNode1(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while(temp) {
            count++;
            temp = temp->next;
        }

        int middleOfNode = (count/2)+1;

        temp = head;
        while(temp) {
            middleOfNode--;
            if(middleOfNode == 0)
                break;
            temp = temp->next;
        }

        return temp;
    }
    
    // Optimal Approach
    // T.C. = O(n/2)
    // S.C. = O(1)
    ListNode* middleNode2(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // We need to move the pointers until fast != NULL (In case of even length LL) 
        // and until fast->next != NULL (In case of odd length LL)  
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    
    ListNode* middleNode(ListNode* head) {
        // Brute Force Approach
        // return middleNode1(head);

        // Optimal Approach
        return middleNode2(head);
    }
};