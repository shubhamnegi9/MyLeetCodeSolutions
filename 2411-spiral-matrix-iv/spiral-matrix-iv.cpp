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
     
        vector<vector<int>> matrix(m, vector<int> (n, -1));
        
        int top = 0;
        int bottom = m-1;
        int left = 0;
        int right = n-1;
        
        while(top <= bottom && left <= right) {
            
            // Left to Right
            for(int i = left; i <= right && head != NULL; i++) {
                matrix[top][i] = head->val;
                head = head->next;
            }
            top++;
            
            // Top to Bottom
            for(int i = top; i <= bottom && head != NULL; i++) {
                matrix[i][right] = head->val;
                head = head->next;
            }
            right--;
            
            // Right to Left
            for(int i = right; i >= left && head != NULL; i--) {
                matrix[bottom][i] = head->val;
                head = head->next;
            }
            bottom--;
            
            // Down to Top
            for(int i = bottom; i >= top && head != NULL; i--) {
                matrix[i][left] = head->val;
                head = head->next;
            }
            left++;
            
        }
        
        return matrix;
    }
};