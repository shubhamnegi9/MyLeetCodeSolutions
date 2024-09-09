class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> result;
        
        int top = 0;
        int bottom = m-1;
        int left = 0;
        int right = n-1;
        
        int id = 0;     // For tracking the direction
        //0   -> left  to right
        //1   -> top   to down
        //2   -> right to left
        //3   -> down  to top
        
        while(top <= bottom && left <= right) {
            
            if(id == 0) {
                // Left to Right
                for(int i = left; i <= right; i++) {
                    result.push_back(matrix[top][i]);
                }
                top++;  // Increment the constant 'top' in loop
            }
            
            if(id == 1) {
                // Top to Bottom
                for(int i = top; i <= bottom; i++) {
                    result.push_back(matrix[i][right]);
                }
                right--;    // Increment the constant 'right' in loop
            }   
            
            if(id == 2) {
                // Right to Left
                for(int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;   // Increment the constant 'bottom' in loop
            }
            
            if(id == 3) { 
                // Bottom to Top
                for(int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++; // Increment the constant 'left' in loop
            }
            
            id = (id+1)%4;  // Increment the 'id' mod 4 so it repeates after reaching 3
            
        }
        
        return result;
    }
};