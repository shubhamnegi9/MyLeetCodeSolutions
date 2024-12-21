class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int> (n, 0));
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;

        int id = 0, num = 1; 

        while(top <= bottom && left <= right) {

            if(id == 0) {
                // Left to Right
                for(int i = left; i <= right; i++) {
                    matrix[top][i] = num;
                    num++;
                }
                top++;  // Increment the constant 'top' in loop
            }

            if(id == 1) {
                // Top to Bottom
                for(int i = top; i <= bottom; i++) {
                    matrix[i][right] = num;
                    num++;
                }
                right--;    // Decrement the constant 'right' in loop
            }   

            if(id == 2) {
                // Right to Left
                for(int i = right; i >= left; i--) {
                    matrix[bottom][i] = num;
                    num++;
                }
                bottom--;   // Decrement the constant 'bottom' in loop
            }

            if(id == 3) { 
                // Bottom to Top
                for(int i = bottom; i >= top; i--) {
                    matrix[i][left] = num;
                    num++;
                }
                left++; // Increment the constant 'left' in loop
            }

            id = (id+1)%4;  // Increment the 'id' mod 4 so it repeates after reaching 3

        }

        return matrix;
    }
};