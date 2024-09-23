class Solution {
public:
    
    int t[51];  // Since only one variable is changing in recursion, so taking 1D array
    
    // Approach 1: Using Recursion
    // T.C. = O(n^2 * n * n)
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
    // T.C. = O(n^2 * n * n)
    int solveMemo(int i, int n, string &s, unordered_set<string> &st) {
        
        // Base Case
        // If out of range then no extra characters
        if(i >= n) {
            return 0;
        }
        
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
    
    int minExtraChar(string s, vector<string>& dict) {
        // Approach 1: Using Recursion
        // return minExtraCharRecur(s, dict);
        
        // Approach 2: Using Top Down Memoization
        return minExtraCharTopDown(s, dict);
    }
};