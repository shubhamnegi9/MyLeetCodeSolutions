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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        if(head->next == NULL) {
            head = NULL;
            return head;
        }
        int sz = 1;
        while(curr->next) {
            sz+=1;
            curr = curr->next;
        }
        int nodeToRemove = sz - n;
        int currNode = 0;
        curr = head;
        while(curr) {
            cout << currNode << endl;
            cout << nodeToRemove << endl;
            if(currNode == nodeToRemove) {
                if(prev != NULL) {
                    prev->next = curr->next;
                    cout << curr->next;
                }
                else {
                    head = head->next;
                }
            }
            currNode++;
            prev = curr;
            curr = curr->next;
        }

        return head;
    }
};