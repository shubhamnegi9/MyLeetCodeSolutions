class Solution {
public:
    int numDecodingsHelper(string& s, int pos, vector<int> &dp) {
        int n = s.size();

        /*
            If the count of decodings till this position
            is already found in the dp table 
            then return it
        */
        if(dp[pos] != -1) {
            return dp[pos];
        }
        
        // Entire string is decoded
        if(pos == n)
            return 1;
        
        // If '0' comes at start in substring, then we cannot decode further
        if(s[pos] == '0')
            return 0;
        
        // count of decodings for this position
        int count = 0;
        
        // On decoding single digit from start
        count += numDecodingsHelper(s, pos+1, dp);

        // On decoding double digits from start
        /*
            Checking if double digits are possible (pos < n-1)
            and double digits are <= "26".
            Checking of double digits >= "10" will be
            handled by above if-condition:
            if(s[pos] == '0')
               return 0;
        */
        if(pos < n-1 && s.substr(pos, 2) <= "26") {
            count += numDecodingsHelper(s, pos+2, dp);
        }

        /* 
        Storing the count in dp table 
        for this pos before returning.
        Can also be written along with 
        return keyword as:
        return dp[pos] = count;
        */
        dp[pos] = count;

        return count;
    }

    int numDecodings(string s) {
        int n = s.size();
        // Creating a DP table of size (n+1)
        // for memorization and filling all
        // values with -1
        vector<int> dp(n+1, -1);
        return numDecodingsHelper(s, 0, dp);
    }
};