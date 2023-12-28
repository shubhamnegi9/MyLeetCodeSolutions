// Defining here will make array stored in heap
// which have more memory
int dp[101][27][101][101];   

class Solution {
public:

    // If defined here will make array stored in stack
    // and because of very large size of array
    // can cause stack overflow
    // int dp[101][27][101][101];   

    int solve(string &s, int i, int prev, int freq, int k ){
        if(k < 0)
            return INT_MAX;
        
        if(i >= s.length())
            return 0;
        
        if(dp[i][prev][freq][k] != -1) {
            return dp[i][prev][freq][k];
        }
        
        int delete_i = solve(s, i+1, prev, freq, k-1);
        
        int keep_i   = 0;
        
        if(s[i] - 'a' == prev) {
             int one_more_added = 0;
             if(freq == 1 || freq == 9 || freq == 99) {
                 one_more_added = 1;
             }
            keep_i = one_more_added + solve(s, i+1, prev, freq+1, k);
        } else {
            keep_i = 1 + solve(s, i+1, s[i]-'a', 1, k);
        }
        
        return dp[i][prev][freq][k] = min(delete_i, keep_i);
    }

    int getLengthOfOptimalCompression(string s, int k) {
        // Using Recursion:
        // return solve(s, 0, 26, 0, k);    // Passed prev_char as 'z' in ASCII initially

        // Using Memoization (Top-Down Approach):
        memset(dp, -1, sizeof(dp));     // Initialized all value to -1
        return solve(s, 0, 26, 0, k);    // Passed prev_char as 'z' in ASCII initially
    }
};