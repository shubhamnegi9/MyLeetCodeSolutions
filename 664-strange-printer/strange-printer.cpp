class Solution {
public:
    vector<vector<int>> t;
    
    // Using Recursion
    int solve(string &s, int l, int r) {
        
        // Only single character, can be printed in 1 turn
        if(l==r) {
            return 1;
        }
        
        // All the characters are printed
        if(l > r) {
            return 0;
        }
        
        int i = l+1;
        // Moving 'i' until the characters are same as s[l]
        while(i <= r && s[i] == s[l]) {
            i++;
        }
        
        // All the characters are same, can be printed in 1 turn
        if(i > r) {
            return 1;
        }        
        
        // Basic Approach
        // Printing all the same characters till 'i-1' in 1 turn and then calling recursion 
        int basic = 1 + solve(s, i, r);
        
        // Greedy Approach
        int greedy = INT_MAX;
        for(int j = i+1; j <= r; j++) {
            if(s[j] == s[l]) {
                int ans = solve(s, i, j-1) + solve(s, j, r);
                greedy = min(greedy, ans);
            }
        }
        
        return min(basic, greedy);
    }
    
     // Using Memoization
    int solveMemo(string &s, int l, int r) {
        
        // Only single character, can be printed in 1 turn
        if(l==r) {
            return 1;
        }
        
        // All the characters are printed
        if(l > r) {
            return 0;
        }
        
        int i = l+1;
        // Moving 'i' until the characters are same as s[l]
        while(i <= r && s[i] == s[l]) {
            i++;
        }
        
        // All the characters are same, can be printed in 1 turn
        if(i > r) {
            return 1;
        }        
        
        if(t[l][r] != -1) {
            return t[l][r];
        }
        
        // Basic Approach
        // Printing all the same characters till 'i-1' in 1 turn and then calling recursion 
        int basic = 1 + solveMemo(s, i, r);
        
        // Greedy Approach
        int greedy = INT_MAX;
        for(int j = i+1; j <= r; j++) {
            if(s[j] == s[l]) {
                int ans = solveMemo(s, i, j-1) + solveMemo(s, j, r);
                greedy = min(greedy, ans);
            }
        }
        
        return t[l][r] = min(basic, greedy);
    }
    
    int strangePrinter(string s) {
        int n = s.length();
        
        // Using Recursion
        // return solve(s, 0, n-1);
        
        // Using Memoization
        t.resize(n+1, vector<int>(n+1, -1));
        return solveMemo(s, 0, n-1);
    }
};