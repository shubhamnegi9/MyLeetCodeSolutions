class Solution {
public:
    int m, n;
    int solve(int row, int col, vector<vector<int>>& grid) {
        
        int ans1 = 0;
        int ans2 = 0;
        int ans3 = 0;
        
        if(row-1 >= 0 && col+1 < n && grid[row-1][col+1] > grid[row][col]) {
            ans1 += solve(row-1, col+1, grid);
        } 
        
        if(col+1 < n && grid[row][col+1] > grid[row][col]) {
            ans2 += solve(row, col+1, grid);
        }
        
        if(row+1 < m && col+1 < n && grid[row+1][col+1] > grid[row][col]) {
            ans3 += solve(row+1, col+1, grid);
        }
        
        return 1 + max({ans1, ans2, ans3});
    }
    
    int maxMoves1(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int mxMoves = 0;
        for(int i = 0; i < m; i++) {
            int moves = solve(i, 0, grid);
            mxMoves = max(mxMoves, moves-1);
        }
        
        return mxMoves;
    }
    
    int solveMemo(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        
        int ans1 = 0;
        int ans2 = 0;
        int ans3 = 0;
        
        if(dp[row][col] != -1)
            return dp[row][col];
        
        if(row-1 >= 0 && col+1 < n && grid[row-1][col+1] > grid[row][col]) {
            ans1 += solveMemo(row-1, col+1, grid, dp);
        } 
        
        if(col+1 < n && grid[row][col+1] > grid[row][col]) {
            ans2 += solveMemo(row, col+1, grid, dp);
        }
        
        if(row+1 < m && col+1 < n && grid[row+1][col+1] > grid[row][col]) {
            ans3 += solveMemo(row+1, col+1, grid, dp);
        }
        
        return dp[row][col] = 1 + max({ans1, ans2, ans3});
    }
    
    int maxMoves2(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int mxMoves = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        for(int i = 0; i < m; i++) {
            int moves = solveMemo(i, 0, grid, dp);
            mxMoves = max(mxMoves, moves-1);
        }
        
        return mxMoves;
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        // return maxMoves1(grid);
        
        return maxMoves2(grid);
    }
};