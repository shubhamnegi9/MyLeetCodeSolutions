class Solution {
public:
    // Using recursion
    int solve(int n) {
        // Invalid 
        if(n<0)
            return 0;

        // Reached ground
        if(n==0)
            return 1;
        
        // Number of steps to reach ground if 1 step is taken
        int oneStep = solve(n-1);
        // Number of steps to reach ground if 2 steps are taken
        int twoStep = solve(n-2);

        // Total Steps to reach gound
        return oneStep + twoStep;

    }

    // Using Top Down Memoization
    int solveMemo(int n, vector<int> &dp) {
        // Invalid 
        if(n<0)
            return 0;

        // Reached ground
        if(n==0)
            return 1;
        
        // If contains in dp table, return it
        if(dp[n] != -1)
            return dp[n];

        // Number of steps to reach ground if 1 step is taken
        int oneStep = solveMemo(n-1, dp);
        // Number of steps to reach ground if 2 steps are taken
        int twoStep = solveMemo(n-2, dp);

        // Total Steps to reach gound
        return dp[n] = oneStep + twoStep;

    }

    // Using Bottom Up Approach
    int solveBottomUp(int n, vector<int> &dp) {
        if(n == 0 || n == 1 || n==2)
            return n;
        
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

    // Using temp variables
    int solveUsingVariables(int n) {
        if(n == 0 || n == 1 || n==2)
            return n;
        
        int a = 1;
        int b = 2;
        int c = 3;
    
        for(int i = 3; i <= n; i++) {
            c = a+b;
            a = b;
            b = c;
        }

        return c;
    }

    int climbStairs(int n) {
        // Using recursion (Gives TLE)
        // return solve(n);

        vector<int> dp(n+1, -1);

        // return solveMemo(n, dp);

        // return solveBottomUp(n, dp);

        return solveUsingVariables(n);
    }
};