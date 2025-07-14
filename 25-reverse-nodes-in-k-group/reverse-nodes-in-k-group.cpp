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
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }

    ListNode* findKthNode(ListNode* temp, int k) {
        k--;    // As we are already standing at first node, and need next kth node 

        /*
            Following loop with break in 2 cases:
            1. k == 0 and temp != NULL, which means there is kth node present
            2. k != 0 and temp == NULL, which means there is no kth node present
        */
        while(k > 0 && temp != NULL) {
            k--;
            temp = temp->next;
        }

        return temp;
    }

    // T.C. = O(n) for reversing every k group + O(n) for finding every kth node
    //      = O(2m)
    // S.C. = O(1)
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;

        while(temp != NULL) {
            ListNode* kNode = findKthNode(temp, k);

            if(kNode == NULL) {         // There are less than k elements ahead of temp
                if(prevNode != NULL)
                    prevNode->next = temp;
                break;
            } 

            ListNode* nextNode = kNode->next;
            kNode->next = NULL;

            reverseLinkedList(temp);    

            /* After reversing, kNode will be at head of reversed linked list, 
                and temp will be at last node of reversed linked list
            */
            
            if(temp == head) {      // This is first kth group linked list, so change the head
                head = kNode;       // kNode will be head of reversed linked list
            } else {
                prevNode->next = kNode;
            }

            prevNode = temp;
            temp = nextNode;
        }

        return head;
    }   
};