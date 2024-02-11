class Solution {
public:
    // DP array for memoization
    // Taking 3D array because 3 variables are changing - rowIndex, colIndex1, colIndex2
    int dp[71][71][71];

    int solve(vector<vector<int>>& grid, int rowIndex, int colIndex1, int colIndex2, int m, int n) {

        // Base Case
        if(rowIndex >= m) {
            return 0;
        }

        if(dp[rowIndex][colIndex1][colIndex2] != -1) 
            return dp[rowIndex][colIndex1][colIndex2];

        // Adding cherry picked by robot 1 to CherrySum
        int cherrySum = grid[rowIndex][colIndex1];
        if(colIndex1 != colIndex2) {
            // Adding cherry picked by robot 2 to CherrySum only if it is not in same cell as robot 1 
            cherrySum += grid[rowIndex][colIndex2];
        }

        int ans = INT_MIN;
        // Checking for every column possibility for robot 1
        for(int i = -1; i <= 1; i++) {
            // For every column possibility of robot 1, checking for every column possibility of robot 2
            for(int j = -1; j <= 1; j++) {
                int newRowIndex = rowIndex+1;      // New row index for both robots (since both are going down)
                int newColIndex1 = colIndex1+i;    // New column index for robot 1 
                int newColIndex2 = colIndex2+j;    // New column index for robot 2

                // Checking for column bounds
                if(newColIndex1 >= 0 && newColIndex1 <= n-1 && newColIndex2 >= 0 && newColIndex2 <= n-1) {
                    // Maximum cherry picked after moving to new indexes
                    ans = max(ans, solve(grid, newRowIndex, newColIndex1, newColIndex2, m, n));
                }
            }
        }

        return dp[rowIndex][colIndex1][colIndex2] = cherrySum+ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        // Number of Rows
        int m = grid.size();
        // Number of Columns
        int n = grid[0].size();

        // Using Recursion + Memoization
        // Starting from 0th row for both robots, and 0th column for first robot and (n-1)th
        // column for second robot 
        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, 0, n-1, m, n);    
    }
};