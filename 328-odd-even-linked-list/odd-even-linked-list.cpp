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
    // T.C. = O(n/2) for step 1 + O(n/2) for step 2 + O(n) for step 3
    //      = O(2n)
    // S.C. = O(n) for array
    ListNode* oddEvenList1(ListNode* head) {
        // Edge case
        if(head == NULL || head->next == NULL)
            return head;

        vector<int> arr;

        // Step 1: Insert all odd indexed nodes in array
        ListNode* temp = head;      // head will be first odd indexed node

        while(temp != NULL && temp->next != NULL) {   // Since we are accessing temp->next->next
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
      
        // In case temp points to last node, its data needs to be added in array
        if(temp != NULL)
            arr.push_back(temp->val);

        
        // Step 2: Insert all even indexed nodes in array
        temp = head->next;      // head->next will be first even indexed node
        while(temp != NULL && temp->next != NULL) {   // Since we are accessing temp->next->next
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
  
        // In case temp points to last node, its data needs to be added in array
        if(temp != NULL)
            arr.push_back(temp->val);

        // Step 3: Data replacement in linked list
        temp = head;
        int i = 0;
        while(temp != NULL) {
            temp->val = arr[i];
            i++;
            temp = temp->next; 
        }

        return head;
    }

    // Optimal Approach
    // T.C. = 2*O(n/2)
    // S.C. = O(1)
    ListNode* oddEvenList2(ListNode* head) {
        // Edge case
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;

        while(even != NULL && even->next != NULL) {
            // Linking odd indexed nodes together and even indexed nodes together
            odd->next = odd->next->next;
            even->next = even->next->next;

            // Move odd and even pointers ahead
            odd = odd->next;
            even = even->next;
        }

        // Link odd indexed linked list to even indexed linked list
        odd->next = evenHead;   
        return head;
    }

    ListNode* oddEvenList(ListNode* head) {
        // Brute Force Approach
        // return oddEvenList1(head);

        // Optimal Approach
        return oddEvenList2(head);
    }
};