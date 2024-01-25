class Solution {
public:

    // Using Recursion
    // T.C. = O(2^m * 2^n) = O(2^(m+n)) 
    int solve(string &s1, string &s2, int i, int j, int m, int n) {
        // Base Case
        if(i >= m || j >= n)
            return 0;           // s1 and s2 does not have anything in common
        
        if(s1[i] == s2[j]) {
            // Add length of common character and move ahead to next characters in both strings
            return 1 + solve(s1, s2, i+1, j+1, m, n);
        }
        else {
            // Return maximum length of common characters by first moving ahead to next char
            // in first string and then in second string
            return max(solve(s1, s2, i+1, j, m, n), solve(s1, s2, i, j+1, m, n));
        }
    }

    // Using Top Down Approach (Recursion + Memoization)
    // T.C. = O((m+1)*(n+1)) = O(m*n)
    int solveMemo(string &s1, string &s2, int i, int j, int m, int n, int dp[][1001]) {
        // Base Case
        if(i >= m || j >= n)
            return 0;           // s1 and s2 does not have anything in common
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i] == s2[j]) {
            // Add length of common character and move ahead to next characters in both strings
            return dp[i][j] = 1 + solveMemo(s1, s2, i+1, j+1, m, n, dp);
        }
        else {
            // Return maximum length of common characters by first moving ahead to next char
            // in first string and then in second string
            return dp[i][j] = max(solveMemo(s1, s2, i+1, j, m, n, dp), solveMemo(s1, s2, i, j+1, m, n, dp));
        }
    }

    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        
        // Using Recursion
        //  return solve(s1, s2, 0, 0, m, n);

        // Using Top Down Approach (Recursion + Memoization)
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        return solveMemo(s1, s2, 0, 0, m, n, dp);
    }
};