class Solution {
public:
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
            // If element in next row is not in same column
            if(nextRow < m && nextCol != col) {
                minSum = min(minSum, curr + solve(grid, nextRow, nextCol, m, n));
            }
        }
        
        return minSum;
    }
        
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
            // If element in next row is not in same column
            if(nextRow < m && nextCol != col) {
                minSum = min(minSum, curr + solveMemo(grid, nextRow, nextCol, m, n, dp));
            }
        }
        
        return dp[row][col] = minSum;
    }
    
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int minSum = INT_MAX;
        int row = 0;
        int dp[201][201];
        memset(dp, -1, sizeof(dp));
        
        // Using Recursion
        // for(int col = 0; col < n; col++) {
        //     minSum = min(minSum, solve(grid, row, col, m, n));
        // }
        
        // Using Top Down Approach
        for(int col = 0; col < n; col++) {
            minSum = min(minSum, solveMemo(grid, row, col, m, n, dp));
        }
        
        return minSum;
    }
};