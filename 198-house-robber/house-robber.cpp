class Solution {
public:

    // Using recursion
    int solve(vector<int> &nums, int i, int n) {
        // Base Case
        // If robber goes out of bound, then he cannot steal any money
        if(i >= n)
            return 0;
        
        // Amount of money if current house is robbed
        int steal = nums[i] + solve(nums, i+2, n); 
        // Amount of money if current house is not robbed
        int skip = solve(nums, i+1, n);

        return max(steal, skip);
    }

    // Using recursion + Memoization (Top-Down Approach)
    int solveMemo(vector<int> &nums, int i, int n, int* dp) {
        // Base Case
        // If robber goes out of bound, then he cannot steal any money
        if(i >= n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        // Amount of money if current house is robbed
        int steal = nums[i] + solveMemo(nums, i+2, n, dp);
        // Amount of money if current house is not robbed
        int skip = solveMemo(nums, i+1, n, dp);

        return dp[i] = max(steal, skip);
    }

    // Using Bottom-Up Approach
    int solveTopDown(vector<int> &nums, int i, int n, vector<int> &t) {
        // t[i] represents maximum stolen money till 'i'th house (or (i-1) indexed house)

        t[0] = 0;   
        t[1] = nums[0];

        for(int i = 2; i <= n; i++) {
            int steal = nums[i-1] + t[i-2];
            int skip = t[i-1];
            t[i] = max(steal, skip);
        }
        
        return t[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        // Using recursion
        // return solve(nums, 0, n);

        // Using recursion + Memoization (Top-Down Approach)
        // int dp[101];
        // memset(dp, -1, sizeof(dp));
        // return solveMemo(nums, 0, n, dp);

        // Using Bottom-Up Approach
        vector<int> t(n+1, -1);
        return solveTopDown(nums, 0, n, t);
    }                              
};