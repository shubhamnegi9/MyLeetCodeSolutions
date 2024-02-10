class Solution {
public:
    bool isPalindromicIterative(int i, int j, string s) {
        while(i <= j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }

    bool isPalindromicRecursive(int i, int j, string &s) {
        
        if(i > j) 
            return true;
        
        if(s[i] == s[j])
            return isPalindromicRecursive(i+1, j-1, s);

        return false;

    }

    bool isPalindromicMemo(int i, int j, string &s, int dp[][1001]) {
        
        if(i > j) 
            return true;
        
        /*
            dp[i][j] stores:
            -1 -> If not solved yet
            1 -> If palindromic
            0 - > If not palindromic
        */
        if(dp[i][j] != -1)
            return dp[i][j];    
        
        if(s[i] == s[j])
            return dp[i][j] = isPalindromicMemo(i+1, j-1, s, dp);

        return dp[i][j] = false;

    }

    // Iterative Way
    int countSubstringsIterative(string s ){
        int n = s.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(isPalindromicIterative(i, j, s))
                    count++;
            }
        }

        return count;
    }

    // Recursive Way
    int countSubstringsRecursive(string s ){
        int n = s.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(isPalindromicRecursive(i, j, s))
                    count++;
            }
        }

        return count;
    }

    // Recursion + Memoization
    int countSubstringsMemo(string s) {
        int n = s.size();
        int count = 0;
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(isPalindromicMemo(i, j, s, dp))
                    count++;
            }
        }

        return count;
    }

    // Bottom Up Approach
    int countSubstringsBottomUp(string &s) {

        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n, false));

        int count = 0;

        for(int L = 1; L <= n; L++) {
            for(int i = 0; i + L <= n; i++) {    // i + L - 1 < n for getting valid j
                int j = i + L - 1;

                // 0 length substring 
                if(i == j) {
                    t[i][i] = true;    // Always palindromic
                }

                // 1 length substring 
                else if(i+1 == j) {
                    t[i][j] = (s[i] == s[j]);   // Check for s[i] == s[j]
                }

                // 2 length substring
                else {
                    t[i][j] = (s[i] == s[j] && t[i+1][j-1]);    // Check for s[i] == s[j] and substring between 'i' and 'j' to be palindromic
                }

                if(t[i][j] == true)
                    count++;

            }
        }

        return count;
    }

    void checkPalindrome(string &s, int i, int j, int n, int &count) {

        while(i >= 0 && j < n && s[i] == s[j]) {
            count+=1;
            i--;    // Moving i to left
            j++;    // Moving j to right
        }
    }

    int countSubstringsSmartApproach(string &s) {
        int n = s.length();
        int count = 0;
        for(int i = 0; i < n; i++) {
            checkPalindrome(s, i, i, n, count);   // Checing for odd length palindromes with center i
            checkPalindrome(s, i, i+1, n, count); // Checing for even length palindromes with center i and i+1
        }

        return count;
    }

    int countSubstrings(string s) {
        // Iterative Way
        // return countSubstringsIterative(s);

        // Recursive Way
        // return countSubstringsRecursive(s);

        // Recursion + Memoization
        // return countSubstringsMemo(s);

        // Bottom Up Approach
        // return countSubstringsBottomUp(s);

        // Smart Approach
        return countSubstringsSmartApproach(s);
    }
};