class Solution {
public:
    
    int t[51];  // Since only one variable is changing in recursion, so taking 1D array
    
    // Approach 1: Using Recursion
    // T.C. = O(2^n * n * n)
    int solve(int i, int n, string &s, unordered_set<string> &st) {
        
        // Base Case
        // If out of range then no extra characters
        if(i >= n) {
            return 0;
        }
        
        // If the character at ith index in string is considered as extra character
        int result = 1 + solve(i+1, n, s, st);      // Adding 1 to result for the extra character at ith index
        
        // If the character at ith index is not considered as extra character
        // Iterating from i to last index to check if any substring is present in dictionary
        for(int j = i; j < n; j++) {
            string str = s.substr(i, j-i+1);   
            if(st.count(str)) {     // substring is present in dictionary
                result = min(result, solve(j+1, n, s, st));
            }
        }
        
        return result;
    }
    
    int minExtraCharRecur(string s, vector<string>& dict) {
        int n = s.length();
        unordered_set<string> st(dict.begin(), dict.end());
        return solve(0, n, s, st);
    }
    
    // Approach 2: Using Top Down Memoization
    // T.C. = O(n * n * n)
    // S.C : O(total numberof characters in dictionary words + n for memoization array)
    int solveMemo(int i, int n, string &s, unordered_set<string> &st) {
        
        // Base Case
        // If out of range then no extra characters
        if(i >= n) {
            return 0;
        }
        
        // If the result is already present in dp array, return from it
        if(t[i] != -1) {
            return t[i];
        }
        
        // If the character at ith index in string is considered as extra character
        int result = 1 + solveMemo(i+1, n, s, st);      // Adding 1 to result for the extra character at ith index
        
        // If the character at ith index is not considered as extra character
        // Iterating from i to last index to check if any substring is present in dictionary
        for(int j = i; j < n; j++) {
            string str = s.substr(i, j-i+1);   
            if(st.count(str)) {     // substring is present in dictionary
                result = min(result, solveMemo(j+1, n, s, st));
            }
        }
        
        return t[i] = result;
    }
    
    int minExtraCharTopDown(string s, vector<string>& dict) {
        int n = s.length();
        unordered_set<string> st(dict.begin(), dict.end());
        memset(t, -1, sizeof(t));
        return solveMemo(0, n, s, st);
    }
    
    // Approach 3: Using Top Down Memoization Using Map
    // T.C. = O(n * n * n)
    // S.C : O(total numberof characters in dictionary words + n for memoization map)
    int solveMemo(int i, int n, string &s, unordered_set<string> &st, unordered_map<int, int> &mpp) {
        
        // Base Case
        // If out of range then no extra characters
        if(i >= n) {
            return 0;
        }
        
        // If the result is already present in map at key 'i', return from it
        if(mpp.count(i)) {
            return mpp[i];
        }
        
        // If the character at ith index in string is considered as extra character
        int result = 1 + solveMemo(i+1, n, s, st, mpp);      // Adding 1 to result for the extra character at ith index
        
        // If the character at ith index is not considered as extra character
        // Iterating from i to last index to check if any substring is present in dictionary
        for(int j = i; j < n; j++) {
            string str = s.substr(i, j-i+1);   
            if(st.count(str)) {     // substring is present in dictionary
                result = min(result, solveMemo(j+1, n, s, st, mpp));
            }
        }
        
        return mpp[i] = result;
    }
    
    int minExtraCharTopDownMap(string s, vector<string>& dict) {
        int n = s.length();
        unordered_set<string> st(dict.begin(), dict.end());
        unordered_map<int, int> mpp;
        return solveMemo(0, n, s, st, mpp);
    }
    
    // Approach 4: Using Bottom Up Approach
    //T.C : O(n^3)
    //S.C : O(n)
    int minExtraCharBottomUp(string s, vector<string>& dict) {
        int n = s.length();
        unordered_set<string> st(dict.begin(), dict.end());
        vector<int> dp(n+1, 0);
        // dp[i] = min extra characters in s from index = i to index = n-1
        // We need to return dp[0]
        
        // Filling dp vector in reverse order so we can calculate dp[0] and return it
        for(int i = n-1; i >= 0; i--) {
            // If the character at ith index in string is considered as extra character
            dp[i] = 1 + dp[i+1];
            
            // If the character at ith index is not considered as extra character
            // Iterating from i to last index to check if any substring is present in dictionary
            for(int j = i; j < n; j++) {
                string str = s.substr(i, j-i+1);   
                if(st.count(str)) {     // substring is present in dictionary
                    dp[i] = min(dp[i], dp[j+1]);
                }
            }
        }
        
        return dp[0];
    }
    
    int minExtraChar(string s, vector<string>& dict) {
        // Approach 1: Using Recursion
        // return minExtraCharRecur(s, dict);
        
        // Approach 2: Using Top Down Memoization
        // return minExtraCharTopDown(s, dict);
        
        // Approach 3: Using Top Down Memoization Using Map
        // return minExtraCharTopDownMap(s, dict);
        
        // Approach 4: Using Bottom Up Approach
        return minExtraCharBottomUp(s, dict);
    }
};