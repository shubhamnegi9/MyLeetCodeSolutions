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

     // Using Bottom Up Approach
     int solveBottomUp(string &s1, string &s2, int m, int n, vector<vector<int>> &t) {
         
        // t[i][j] represents length of longest LCS in string s1 of length 'i' and string s2 of length 'j'
        // t[m][n] represents length of longest LCS in string s1 of length 'm' and string s2 of length 'n'

        // s2 is of length 0
        // s1 and s2 have no characters in common
        for(int i = 0; i <= m; i++) {
            t[i][0] = 0;   
        }
        
        // s1 is of length 0
        // s1 and s2 have no characters in common
        for(int j = 0; j <= n; j++) {
            t[0][j] = 0;
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                // Common character found
                if(s1[i-1] == s2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];     // 1 + t[i+1][j+1] cannot be written as t[i+1][j+1] is not evaluated yet
                }
                else {
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }

        return t[m][n];
     }

    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        
        // Using Recursion
        //  return solve(s1, s2, 0, 0, m, n);

        // Using Top Down Approach (Recursion + Memoization)
        // int dp[1001][1001];
        // memset(dp, -1, sizeof(dp));
        // return solveMemo(s1, s2, 0, 0, m, n, dp);

        // Using Bottom Up Approach
        vector<vector<int>> t(m+1, vector<int>(n+1));
        return solveBottomUp(s1, s2, m, n, t);
    }
};