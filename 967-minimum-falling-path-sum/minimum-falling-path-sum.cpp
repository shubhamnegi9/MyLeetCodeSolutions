class Solution {
public:
    int n;
    int dp[101][101];

    // Using Recursion
    int solve(vector<vector<int>>& matrix, int row, int col) {
        // Base case
        // If reached to last row, return that element
        if(row == n-1)
            return matrix[row][col];
        
        int curr = matrix[row][col];
        int minSum = INT_MAX;

        // Finding minimum sum takig bottom left element
        if(row+1 < n && col-1 >= 0)
            minSum = min(minSum, curr + solve(matrix, row+1, col-1));
        // Finding minimum sum taking bottom element
        if(row+1 < n)
            minSum = min(minSum, curr + solve(matrix, row+1, col));
        // Finding minimum sum taking bottom right element
        if(row+1 < n && col+1 < n) 
            minSum = min(minSum, curr + solve(matrix, row+1, col+1));

        return minSum;
    }

    // Using Bottom Up Memoization
    // (New test Case has been added, this will give TLE in last Test Case) 
    int solveMemo(vector<vector<int>>& matrix, int row, int col) {
        // Base case
        // If reached to last row, return that element
        if(row == n-1)
            return matrix[row][col];
        
        // If found in dp table, return from it
        if(dp[row][col] != -1)
            return dp[row][col];
        
        int curr = matrix[row][col];
        int minSum = INT_MAX;

        // Finding minimum sum takig bottom left element
        if(row+1 < n && col-1 >= 0)
            minSum = min(minSum, curr + solveMemo(matrix, row+1, col-1));
        // Finding minimum sum taking bottom element
        if(row+1 < n)
            minSum = min(minSum, curr + solveMemo(matrix, row+1, col));
        // Finding minimum sum taking bottom right element
        if(row+1 < n && col+1 < n) 
            minSum = min(minSum, curr + solveMemo(matrix, row+1, col+1));

        return dp[row][col] = minSum;
    }

    // Using Top Down Approach
    int solveTopDown(vector<vector<int>>& matrix, vector<vector<int>>& t) {
        // Filling first row of 't' vector same as matrix
        for(int col = 0; col < n; col++) {
            t[0][col] = matrix[0][col];
        }

        // For the remainin rows in 't', choosing the minimum out of top, topLeft
        // and topRight value and adding it to current value
        for(int row = 1; row < n; row++) {
            for(int col = 0; col < n; col++) {
                int topLeft = INT_MAX, topRight = INT_MAX;
                if(col-1 >= 0)
                    topLeft = t[row-1][col-1];
                if(col+1 < n)
                    topRight = t[row-1][col+1];
                t[row][col] = matrix[row][col] + min({t[row-1][col], topLeft, topRight});
            }
        }

        // Iterating in the last row of 't' vector and finding the minimum sum
        int minSum = INT_MAX;
        for(int col = 0; col < n; col++) {
            minSum = min(minSum, t[n-1][col]);
        }

        return minSum;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        int minSum = INT_MAX;
        int row = 0;

        // Using Recursion 
        // for(int col = 0; col < n; col++) {
        //     minSum = min(minSum, solve(matrix, row, col));
        // }

        // Using Bottom Up Memoization 
        // memset(dp, -1, sizeof(dp));
        // for(int col = 0; col < n; col++) {
        //     minSum = min(minSum, solveMemo(matrix, row, col));
        // }

        // Using Top Down Approach
        vector<vector<int>> t(n, vector<int>(n));
        minSum = solveTopDown(matrix, t);

        return minSum;
    }
};