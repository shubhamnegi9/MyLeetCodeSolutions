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
        
        int num = 1;
        while(left <= right && top <= bottom) {
            
            // Left to Right
            for(int i = left; i <= right; i++) {
                matrix[top][i] = num;
                num++;
            }
            top++;
            
            // Top to Bottom
            for(int i = top; i <= bottom; i++) {
                matrix[i][right] = num;
                num++;
            }
            right--;
            
            // Right to Left
            for(int i = right; i >= left; i--) {
                matrix[bottom][i] = num;
                num++;
            }
            bottom--;
            
            // Bottom to Top
            for(int i = bottom; i >= top; i--) {
                matrix[i][left] = num;
                num++;
            }
            left++;
            
        }
        
        return matrix;
    }
};