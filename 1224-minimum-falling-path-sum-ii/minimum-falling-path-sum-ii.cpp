class Solution {
public:
    // Using Recursion
    // T.C. = O(n^n * n)
    // S.C. = O(1)
    int solve(vector<vector<int>>& grid, int row, int col, int m, int n) {
        // Base case
        // If reached to last row, return that element
        if(row == m-1) {
            return grid[row][col];
        }
        
        int curr = grid[row][col];
        int minSum = INT_MAX;
        
        int nextRow = row+1;
        // Iterate in whole column of next row
        for(int nextCol = 0; nextCol < n; nextCol++) {
            // If element in next row is not in same column and is not out of bound
            if(nextRow < m && nextCol != col) {
                minSum = min(minSum, curr + solve(grid, nextRow, nextCol, m, n));
            }
        }
        
        return minSum;
    }
        
    // Using Top Down Memoization Approach
    // T.C. = O(n*n * n)
    // S.C. = O(n*n)
    int solveMemo(vector<vector<int>>& grid, int row, int col, int m, int n, int dp[][201]) {
        // Base case
        // If reached to last row, return that element
        if(row == m-1) {
            return grid[row][col];
        }
        
        if(dp[row][col] != -1) {
            return dp[row][col];
        }
        
        int curr = grid[row][col];
        int minSum = INT_MAX;
        
        int nextRow = row+1;
        // Iterate in whole column of next row
        for(int nextCol = 0; nextCol < n; nextCol++) {
            // If element in next row is not in same column and is not out of bound
            if(nextRow < m && nextCol != col) {
                minSum = min(minSum, curr + solveMemo(grid, nextRow, nextCol, m, n, dp));
            }
        }
        
        return dp[row][col] = minSum;
    }
    
    // Using Bottom Up Approach
    // T.C. = O(n*n * n)
    // S.C. = O(n*n)
    int solveBottomUp(vector<vector<int>>& grid, vector<vector<int>>& t, int m, int n) {
    
        // t[i][j] : Minimum Falling Path Sum from row 'i' to row 'm-1' if we choose column 'j' in the 'i'th row 
        // Since in vector 't', for t[row][col], we don't known the value of t[row+i][col+j], therefore we will fill vector 't' in reverse order from bottom to up
        
        // Filling last row of 't' vector same as grid
        for(int col = 0; col < n; col++) {
            t[m-1][col] = grid[m-1][col];
        }
        
        // Filling remaining rows of 't' in bottom-up manner
        for(int row = m-2; row >= 0; row--) {
            for(int col = 0; col < n; col++) {
                int ans = INT_MAX;
                int curr = grid[row][col];
                int nextRow = row+1;
                for(int nextCol = 0; nextCol < n; nextCol++) {
                    // If element in next row is not in same column and is not out of bound
                    if(nextRow < m && nextCol != col) {
                        ans = min(ans, curr+t[nextRow][nextCol]);
                    }
                }
                t[row][col] = ans;
            }
        }
        
        int minSum = INT_MAX;
        // Iterating in the first row of 't' vector and finding the minimum sum
        for(int col = 0; col < n; col++) {
            minSum = min(minSum, t[0][col]);
        }
        
        return minSum;
    }
    
    // Using Bottom Up Optimized Approach
    int solveBottomUpOptimized(vector<vector<int>>& grid, vector<vector<int>>& t, int m, int n) {
    
        // t[i][j] : Minimum Falling Path Sum from row 'i' to row 'm-1' if we choose column 'j' in the 'i'th row 
        // Since in vector 't', for t[row][col], we don't known the value of t[row+i][col+j], therefore we will fill vector 't' in reverse order from bottom to up
        
        // Variables for storing the column index containing the minimum and next minimum value in the next row 
        int nextMinCol1 = -1;
        int nextMinCol2 = -1;
        
        // Filling last row of 't' vector same as grid
        for(int col = 0; col < n; col++) {
            t[m-1][col] = grid[m-1][col];
            
            // Intializing nextMinCol1 and nextMinCol2
            if(nextMinCol1 == -1 || t[m-1][col] <= t[m-1][nextMinCol1]) {
                nextMinCol2 = nextMinCol1;
                nextMinCol1 = col;
            }
            else if(nextMinCol2 == -1 || t[m-1][col] <= t[m-1][nextMinCol2]) {
                nextMinCol2 = col;
            }
                
        }
        
        // Filling remaining rows of 't' in bottom-up manner
        for(int row = m-2; row >= 0; row--) {
            // Variables for storing the column index containing the minimum and next minimum value in the current row
            int minCol1 = -1;
            int minCol2 = -1;
            for(int col = 0; col < n; col++) {
                int curr = grid[row][col];
                int nextRow = row+1;
                
                // This for-loop is not required anymore now:
                // for(int nextCol = 0; nextCol < n; nextCol++) {
                //     // If element in next row is not in same column and is not out of bound
                //     if(nextRow < m && nextCol != col) {
                //         ans = min(ans, curr+t[nextRow][nextCol]);
                //     }
                // }
                // t[row][col] = ans;
                
                
                // Taking nextMinCol1 value if it is not matching with current column value, otherwise taking nextMinCol2 value
                if(col != nextMinCol1) {
                    t[row][col] = curr+t[nextRow][nextMinCol1];
                }
                else {
                    t[row][col] = curr+t[nextRow][nextMinCol2];
                }
                
                // Intializing minCol1 and minCol2
                if(minCol1 == -1 || t[row][col] <= t[row][minCol1]) {
                    minCol2 = minCol1;
                    minCol1 = col;
                }
                else if(minCol2 == -1 || t[row][col] <= t[row][minCol2]) {
                    minCol2 = col;
                }
            }
            // Assigning minCol1 and minCol2 to nextMinCol1 and nextMinCol2 for further iteration
            nextMinCol1 = minCol1;
            nextMinCol2 = minCol2;
        }
        
        // This for-loop is not required anymore now:
        // int minSum = INT_MAX;
        // // Iterating in the first row of 't' vector and finding the minimum sum
        // for(int col = 0; col < n; col++) {
        //     minSum = min(minSum, t[0][col]);
        // }
        
        // t[0][nextMinCol1] cell contains minimum sum
        return t[0][nextMinCol1];
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size();        
        int n = grid[0].size(); // Could also use same variables for no. of rows and columns for (n X n) grid
        int minSum = INT_MAX;
        int row = 0;
        int dp[201][201];
        memset(dp, -1, sizeof(dp));
        
        // Using Recursion
        // for(int col = 0; col < n; col++) {
        //     minSum = min(minSum, solve(grid, row, col, m, n));
        // }
        
        // Using Top Down Approach
        // for(int col = 0; col < n; col++) {
        //     minSum = min(minSum, solveMemo(grid, row, col, m, n, dp));
        // }
        
        // Using Bottom Up Approach
        // vector<vector<int>> t(m, vector<int> (n, INT_MAX));  // Vector of size (mXn) and intitalized with INT_MAX (Since we need to find minimum)
        // minSum = solveBottomUp(grid, t, m, n);  
        
        // Using Bottom Up Optimized Approach
        vector<vector<int>> t(m, vector<int> (n, INT_MAX));  // Vector of size (mXn) and intitalized with INT_MAX (Since we need to find minimum)
        minSum = solveBottomUpOptimized(grid, t, m, n);  
        
        return minSum;
    }
};