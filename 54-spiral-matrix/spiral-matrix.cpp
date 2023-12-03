class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();      // ROWS
        int m = matrix[0].size();   // COLUMNS
        vector<int> ans;

        // Boundaries of spiral traversal
        int left = 0, right = m-1, top = 0, bottom = n-1;

        while((left <= right) && (top <= bottom)) {

            // Printing towards right
            for(int i = left; i <= right; i++) {
                // cout << matrix[top][i] << " ";
                ans.push_back(matrix[top][i]);
            }
            top++;

            // Printing towards bottom
            for(int i = top; i <= bottom; i++) {
                // cout << matrix[i][right] << " ";
                ans.push_back(matrix[i][right]);
            }
            right--;

            // Printing towards left
            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                    // cout << matrix[bottom][i] << " ";
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Printing towards top
            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                    // cout << matrix[i][left] << " ";
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};