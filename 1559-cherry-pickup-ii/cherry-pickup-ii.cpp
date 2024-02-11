class Solution {
public:
    // DP array for memoization
    // Taking 3D array because 3 variables are changing - rowIndex, colIndex1, colIndex2
    int dp[71][71][71];

    // Using Recursion + Memoization
    // Top Down Approach
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

    // Using Bottom Up Approach
    int solveBottomUp(vector<vector<int>>& grid, int m, int n) {
        
        // Taking 3D array because 3 variables are changing - rowIndex, colIndex1, colIndex2
        int t[71][71][71] = {0};

        // t[row][col1][col2] represents maximum cherries collected by robot1 till (row, col1) 
        // and robot2 till (row, col2)
        
        // Filling for first row in t. Robot1 standing at 0th column and Robot2 standing at (n-1)th column
        t[0][0][n-1] = (n==1) ? grid[0][0] : grid[0][0] + grid[0][n-1];     // Checking for same cell and picking cherry only one time

        // Filling for remaining rows in t
        for(int row = 1; row < m; row++) {
            for(int col1 = 0; col1 <= min(row, n-1); col1++) {  // min(row, n-1) for checking bounds
                for(int col2 = max(0, n-row-1); col2 < n; col2++) {    // max(0, n-row-1) for checking bounds
                    
                    // Checking for all the possibilities from previous row and finding maximum
                    int prevRowMax = 0;
                    for(int prevCol1 = max(0,col1-1); prevCol1 <= min(col1+1, n-1); prevCol1++) {   // max(0,col1-1) and min(col1+1, n-1) for checking bounds
                        for(int prevCol2 = max(0, col2-1); prevCol2 <= min(col2+1, n-1); prevCol2++) {  // max(0, col2-1) and min(col2+1, n-1) for checking bounds
                            prevRowMax = max(prevRowMax, t[row-1][prevCol1][prevCol2]);
                        }
                    }

                    if(col1 == col2) {  // Checking for same cell and picking cherry only one time
                        t[row][col1][col2] = prevRowMax + grid[row][col1];
                    }
                    else {
                        t[row][col1][col2] = prevRowMax + grid[row][col1] + grid[row][col2];
                    }
                }
            }
        }

        // Iterating in the last row of 't' and finding the maximum cherry sum
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans = max(ans, t[m-1][i][j]);
            }
        }

        return ans;
    } 

    // Using Bottom Up Optimized Approach
    int solveBottomUpOptimized(vector<vector<int>>& grid, int m, int n) {
        
        // Taking 2D array 'prev' for storing values for previous row/state
        vector<vector<int>> prev(71, vector<int>(71, 0));
        
        // Filling for row in prev. Robot1 standing at 0th column and Robot2 standing at (n-1)th column
        prev[0][n-1] = (n==1) ? grid[0][0] : grid[0][0] + grid[0][n-1];     // Checking for same cell and picking cherry only one time


        for(int row = 1; row < m; row++) {
            // 2D vector for current row
            vector<vector<int>> curr(71, vector<int>(71, 0));

            for(int col1 = 0; col1 <= min(row, n-1); col1++) {  // min(row, n-1) for checking bounds
                for(int col2 = max(0, n-row-1); col2 < n; col2++) {    // max(0, n-row-1) for checking bounds
                    
                    // Checking for all the possibilities from previous row and finding maximum
                    int prevRowMax = 0;
                    for(int prevCol1 = max(0,col1-1); prevCol1 <= min(col1+1, n-1); prevCol1++) {   // max(0,col1-1) and min(col1+1, n-1) for checking bounds
                        for(int prevCol2 = max(0, col2-1); prevCol2 <= min(col2+1, n-1); prevCol2++) {  // max(0, col2-1) and min(col2+1, n-1) for checking bounds
                            prevRowMax = max(prevRowMax, prev[prevCol1][prevCol2]);
                        }
                    }

                    if(col1 == col2) {  // Checking for same cell and picking cherry only one time
                        curr[col1][col2] = prevRowMax + grid[row][col1];
                    }
                    else {
                        curr[col1][col2] = prevRowMax + grid[row][col1] + grid[row][col2];
                    }
                }
            }

            prev = curr;    // Making current row as previous for next iteration
        }

        // Iterating in prev and finding the maximum cherry sum
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans = max(ans, prev[i][j]);
            }
        }

        return ans;
    } 


    int cherryPickup(vector<vector<int>>& grid) {
        // Number of Rows
        int m = grid.size();
        // Number of Columns
        int n = grid[0].size();

        // Using Recursion + Memoization
        // Starting from 0th row for both robots, and 0th column for first robot and (n-1)th
        // column for second robot 
        // memset(dp, -1, sizeof(dp));
        // return solve(grid, 0, 0, n-1, m, n);    

        // Using Bottom Up Approach
        // return solveBottomUp(grid, m, n);

        // Using Optimized Bottom Up Approach
        return solveBottomUpOptimized(grid, m, n);
    }
};