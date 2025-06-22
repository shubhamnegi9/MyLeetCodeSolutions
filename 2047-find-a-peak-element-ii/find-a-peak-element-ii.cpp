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

    int findMaxElementRow(vector<vector<int>>& mat, int m, int n, int col) {
        int maxEle = -1, row = 0;
        for(int i = 0; i < m; i++) {    
            if(mat[i][col] > maxEle) {
                maxEle = mat[i][col];
                row = i;
            }
        }

        return row;
    }

    // Optimal approach
    // T.C. = O(m * logn)
    // S.C. = O(1)
    vector<int> findPeakGrid2(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int low = 0, high = n-1;

        while(low <= high) {
            int mid = (low+high)/2; 
            // Finding row index of maximum element in mid column
            int row = findMaxElementRow(mat, m, n, mid);
            // Checking for out of bounds
            int left = (mid-1 >= 0) ? mat[row][mid-1] : -1;
            int right = (mid+1 < n) ? mat[row][mid+1] : -1;
            
            if(mat[row][mid] > left && mat[row][mid] > right) {
                return {row, mid};
            } else if(left > mat[row][mid]) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return {-1, -1};
    }


    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // Brute Force Approach
        // return findPeakGrid1(mat);

        // Optimal approach
        return findPeakGrid2(mat);
    }
};