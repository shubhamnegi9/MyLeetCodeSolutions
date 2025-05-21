class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m-1, left = 0, right = n-1;
        vector<int> result;

        while(top <= bottom && left <= right) {
            // Right
            for(int j = left; j <= right; j++) {
                result.push_back(matrix[top][j]);
            }
            top++;

            // Bottom
            for(int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;

            if(top <= bottom) {
                // Left
                for(int j = right; j >= left; j--) {
                    result.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            if(left <= right) {
                // Top
                for(int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return result;
    }
};