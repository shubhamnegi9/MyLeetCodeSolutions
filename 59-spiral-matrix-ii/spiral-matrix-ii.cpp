class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        if(n == 0) {
            return {};
        }
        
        vector<vector<int>> matrix(n, vector<int> (n, 0));
        
        int left = 0;
        int right = n-1;
        int top = 0;
        int bottom = n-1;

        int id = 0;     // For tracking the direction
        //0   -> left  to right
        //1   -> top   to down
        //2   -> right to left
        //3   -> down  to top
        
        int num = 1;
        while(left <= right && top <= bottom) {
            
            if(id == 0) {
                // Left to Right
                for(int i = left; i <= right; i++) {
                    matrix[top][i] = num;
                    num++;
                }
                top++;
            }
            
            if(id == 1) {
                // Top to Bottom
                for(int i = top; i <= bottom; i++) {
                    matrix[i][right] = num;
                    num++;
                }
                right--;
            }
            
            if(id == 2) {
                // Right to Left
                for(int i = right; i >= left; i--) {
                    matrix[bottom][i] = num;
                    num++;
                }
                bottom--;
            }
            
            if(id == 3) {
                // Bottom to Top
                for(int i = bottom; i >= top; i--) {
                    matrix[i][left] = num;
                    num++;
                }
                left++;
            }
            
            id = (id+1)%4;  // Increment the 'id' mod 4 so it repeates after reaching 3
        }
        
        return matrix;
    }
};