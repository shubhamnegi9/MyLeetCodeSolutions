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

    int countSubstrings(string s) {
        // Iterative Way
        // return countSubstringsIterative(s);

        // Recursive Way
        // return countSubstringsRecursive(s);

        // Recursion + Memoization
        return countSubstringsMemo(s);
    
    }
};