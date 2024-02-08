class Solution {
public:

    // Top Down Approach (Recursion+Memoization)
    int solve(int n, int dp[]) {
        // Base Case
        if(n == 0) 
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
        int res = 0;
        int minCount = INT_MAX;
        // Iterating from 1 till square of number is less than n
        for(int i = 1; i*i <= n; i++) {
            // Adding 1 for current square element count and calling recursion for 
            // remaining number (n - i*i)
            res = 1 + solve(n-i*i, dp); 
            minCount = min(minCount, res);
        }

        return dp[n] = minCount;
    }

    // Bottom Up Approach
    int solveBottomUp(int n, vector<int> &t) {

        // t[i] represents minimum count of perfect squares to get i

        t[0] = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j*j <= i; j++) {
                t[i] = min(t[i], 1 + t[i-j*j]);
            }
        }

        return t[n];
    }

    int numSquares(int n) {
        // Top Down Approach (Recursion+Memoization)
        // int dp[10001];
        // memset(dp, -1, sizeof(dp));
        // return solve(n, dp);

        // Bottom Up Approach
        vector<int> t(n+1, 100000);
        return solveBottomUp(n, t);
    }
};