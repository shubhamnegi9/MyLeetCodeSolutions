class Solution {
public:
    // Using Recursion
    int solve(int i, vector<int>& arr, int k, int n) {
        // Base Case
        if(i >= n)
            return 0;
        
        int result = INT_MIN;
        int curr_max = -1;
        for(int j = i; j < n && j-i+1 <= k; j++) {
            curr_max = max(curr_max, arr[j]);
            result = max(result, (j-i+1)*curr_max + solve(j+1, arr, k, n));
        }

        return result;
    }

    // Using Recursion + Memoization
    // Top Down Approach
    int solveMemo(int i, vector<int>& arr, int k, int n, int dp[]) {
        // Base Case
        if(i >= n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int result = INT_MIN;
        int curr_max = -1;
        for(int j = i; j < n && j-i+1 <= k; j++) {
            curr_max = max(curr_max, arr[j]);
            result = max(result, (j-i+1)*curr_max + solveMemo(j+1, arr, k, n, dp));
        }

        return dp[i] = result;
    }

    
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n= arr.size();
        // return solve(0, arr, k, n);

        int dp[501];
        memset(dp, -1, sizeof(dp));
        return solveMemo(0, arr, k, n, dp);
    }
};