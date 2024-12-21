class Solution {
public:
    // Optimal Approach 1
    vector<int> spiralOrder1(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = n-1, top =- 0, bottom = m-1;
        vector<int> result;
        
        while(left <= right && top <= bottom) {
            
            // Right
            for(int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;
            
            // Down
            for(int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;
            
            // Left
            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            // Top
            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        
        return result;
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        return spiralOrder1(matrix);
    }
};