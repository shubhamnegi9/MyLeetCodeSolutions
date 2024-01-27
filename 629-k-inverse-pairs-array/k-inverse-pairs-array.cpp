class Solution {
public:

    int MOD = 1e9+7;

    // Using Recursion
    // T.C. = O(k^n), S.C. = Size of recursion tree
    int solve(int n, int k) {
        // Base Cases
        
        // If no element is present
        if(n == 0)
            return 0;
        
        // Number of inversions = 0 only possible in one way if array is sorted
        if(k == 0)
            return 1;
        
        int res = 0;
        // Maximum inversions cannot be more than (n-1)
        for(int inv = 0; inv <= min(n-1, k); inv++) {
            res = (res % MOD + solve(n-1, k-inv) % MOD) % MOD;
        }

        return res;
    }

    // Using Top Down (Recursion + Memoization)
    // T.C. = O(n*k*n-1) = O(n*k*n), S.C. = O(n*k) 
    int solveMemo(int n, int k, int dp[][1001]) {
        // Base Cases
        
        // If no element is present
        if(n == 0)
            return 0;
        
        // Number of inversions = 0 only possible in one way if array is sorted
        if(k == 0)
            return 1;
        
        // If present in dp table, return from it
        if(dp[n][k] != -1) {
            return dp[n][k];
        }
        
        int res = 0;
        // Maximum inversions cannot be more than (n-1)
        for(int inv = 0; inv <= min(n-1, k); inv++) {
            res = (res % MOD + solveMemo(n-1, k-inv, dp) % MOD) % MOD;
        }

        // Store result in dp table while returning
        return dp[n][k] = res;
    }

    // Using Bottom Up Approach
    // T.C. = O(n*k*n-1) = O(n*k*n), S.C. = O(n*k) 
    int solveBottomUp(int n, int k) {

        // row -> number of elements
        // column -> number of inversions
        vector<vector<int>> t(n+1, vector<int>(k+1, 0));

        // t[i][j] represents total number of arrays of size 'i' and exactly 'j' inversions 

        // Number of inversions = 0 only possible in one way if array is sorted
        for(int i = 0; i <= n; i++) {
            t[i][0] = 1;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= k; j++) {
                for(int inv = 0; inv <= min(i-1, j); inv++) {
                    t[i][j] = (t[i][j] % MOD + t[i-1][j-inv] % MOD) % MOD;
                }
            }
        }

        return t[n][k];
    }

    // Using Optimal Bottom Up Approach
    // T.C. = O(n*k), S.C. = O(n*k)
    int solveBottomUpOptimal(int n, int k) {

        // row -> number of elements
        // column -> number of inversions
        vector<vector<int>> t(n+1, vector<int>(k+1, 0));

        // t[i][j] represents total number of arrays of size 'i' and exactly 'j' inversions 

        // Number of inversions = 0 only possible in one way if array is sorted
        for(int i = 0; i <= n; i++) {
            t[i][0] = 1;
        }

        for(int i = 1; i <= n; i++) {
            long long cumSum = 1; // t[i-1][0] will be 1 
            for(int j = 1; j <= k; j++) {
                // Taking cumulative sum of only last 'i' elements in previous row
                cumSum += t[i-1][j];
                if(j >= i) {
                    cumSum -= t[i-1][j-i];
                }
                
                // Assign cumulative sum to current element
                t[i][j] = cumSum % MOD;
            }
        }

        return t[n][k];
    }

    int kInversePairs(int n, int k) {
        // Using Recursion
        // return solve(n, k);

        // Using Top Down (Recursion + Memoization)
        // int dp[1001][1001];
        // memset(dp, -1, sizeof(dp));
        // return solveMemo(n, k, dp);

        // Using Bottom Up Approach
        // return solveBottomUp(n, k); 

        // Using Optimal Bottom Up Approach
        return solveBottomUpOptimal(n, k);
    }
};