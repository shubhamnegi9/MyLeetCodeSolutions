class Solution {
public:
    // Brute Force Approach
    // T.C. = O(4*m*n)
    // S.C. = O(1)
    vector<int> findPeakGrid1(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // Checking for out of bounds
                int left = (j-1 >= 0) ? mat[i][j-1] : -1;
                int right = (j+1 < n) ? mat[i][j+1] : -1;
                int top = (i-1 >= 0) ? mat[i-1][j] : -1;
                int bottom = (i+1 < m) ? mat[i+1][j] : -1;

                if(mat[i][j] > top && mat[i][j] > bottom && mat[i][j] > left && mat[i][j] > right) {
                    return {i, j};
                }
            }
        }

        return {-1, -1};
    }
    
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // Brute Force Approach
        return findPeakGrid1(mat);
    }
};