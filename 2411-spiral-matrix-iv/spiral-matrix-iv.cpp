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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int left = 0, right = n-1, top = 0, bottom = m-1;
        int id = 0;
        vector<vector<int>> result(m, vector<int> (n, -1));
        
        while(left <= right && top <= bottom) {
            
            if(id == 0) {
                // Left
                for(int i = left; i <= right && head != NULL; i++) {
                    result[top][i] = head->val;
                    head = head->next;
                }
                top++;
            }
            else if(id == 1) {
                // Down
                for(int i = top; i <= bottom && head != NULL ; i++) {
                    result[i][right] = head->val;
                    head = head->next;
                }
                right--;
            }
            else if(id == 2) {
                // Right
                for(int i = right; i >= left && head != NULL; i--) {
                    result[bottom][i] = head->val;
                    head = head->next;
                }
                bottom--;
            }
            else {
                // Top
                for(int i = bottom; i >= top && head != NULL; i--) {
                    result[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }
            
            id = (id+1)%4;
        }
        
        return result;
    }
};