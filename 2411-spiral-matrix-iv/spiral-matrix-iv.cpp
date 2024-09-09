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
        
        int id = 0;     // For tracking the direction
        //0   -> left  to right
        //1   -> top   to down
        //2   -> right to left
        //3   -> down  to top

        while(top <= bottom && left <= right) {     // We will not check for (head != NULL) here, as it can be possible that head is not null when it reaches here but later it can become null in any of the inner loops and on doing head->val it will give error. 
            
            if(id == 0) {
                // Left to Right
                for(int i = left; i <= right && head != NULL; i++) {
                    matrix[top][i] = head->val;
                    head = head->next;
                }
                top++;
            }
            
            if(id == 1) {
                // Top to Bottom
                for(int i = top; i <= bottom && head != NULL; i++) {
                    matrix[i][right] = head->val;
                    head = head->next;
                }
                right--;
            }
            
            if(id == 2) {
                // Right to Left
                for(int i = right; i >= left && head != NULL; i--) {
                    matrix[bottom][i] = head->val;
                    head = head->next;
                }
                bottom--;
            }
            
            if(id == 3) {
                // Down to Top
                for(int i = bottom; i >= top && head != NULL; i--) {
                    matrix[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }
            
            id = (id+1)%4;  // Increment the 'id' mod 4 so it repeates after reaching 3
        }
        
        return matrix;
    }
};