class Solution {
public:
    
    int countSteps(int ringIndex, int i, int m) {
        
        // Number of steps to spell the current key character by rotating the ring anticlockwise
        int anticlockWiseSteps = abs(i - ringIndex);
        
        // Number of steps to spell the current key character by rotating the ring clockwise
        int clockWiseSteps = m - anticlockWiseSteps;
        
        // Returning the minimum of both steps
        return min(anticlockWiseSteps, clockWiseSteps);
    }
    
    
    // Using recursion
    int solve(string &ring, string &key, int ringIndex, int keyIndex, int m, int n) {
        
        // ringIndex represents the index of the character which is present at 12:00 direction in ring
        
        // Base Case : If all characters in key are spelled
        if(keyIndex == n) {
            return 0;
        }
        
        int result = INT_MAX;
        // Iterate in ring and check which character in ring is matching with the current key character
        for(int i = 0; i < m; i++) {
            if(ring[i] == key[keyIndex]) {
                // Number of steps to spell the current key character by rotating the ring
                // 1 is added for step to press the center button to spell
                int steps  = 1 + countSteps(ringIndex, i, m);
                
                // Total steps to spell all the remaining key characters 
                // The current ith ring character index which matches with the current key character becomes the ring character for the next recursive call
                int totalSteps = steps + solve(ring, key, i, keyIndex+1, m, n);
                
                // Storing the minimum steps to spell in case the current key character matches with more than 1 ring characters
                result = min(result, totalSteps);
            }
        }
        
        
        return result;
    }
    
    // Using Top-Down Memoization
    int solveMemo(string &ring, string &key, int ringIndex, int keyIndex, int m, int n, int dp[][101]) {
        
        // ringIndex represents the index of the character which is present at 12:00 direction in ring
        
        // Base Case : If all characters in key are spelled
        if(keyIndex == n) {
            return 0;
        }
        
        // If present in dp table, return from it
        if(dp[ringIndex][keyIndex] != -1) {
            return dp[ringIndex][keyIndex];
        }
        
        int result = INT_MAX;
        // Iterate in ring and check which character in ring is matching with the current key character
        for(int i = 0; i < m; i++) {
            if(ring[i] == key[keyIndex]) {
                // Number of steps to spell the current key character by rotating the ring
                // 1 is added for step to press the center button to spell
                int steps  = 1 + countSteps(ringIndex, i, m);
                
                // Total steps to spell all the remaining key characters 
                // The current ith ring character index which matches with the current key character becomes the ring character for the next recursive call
                int totalSteps = steps + solveMemo(ring, key, i, keyIndex+1, m, n, dp);
                
                // Storing the minimum steps to spell in case the current key character matches with more than 1 ring characters
                result = min(result, totalSteps);
            }
        }
        
        
        //Store result in dp table
        return dp[ringIndex][keyIndex] = result;
    }
    
    // Using Bottom Up Approach
    int solveBottomUp(string &ring, string &key, int m, int n, vector<vector<int>> &t) {
        
        // t[ringIndex][keyIndex] : Min. steps to spell key[keyIndex] character when ring[ringIndex] character is at 12:00 direction in ring
        
        // Filling the last column of table as per base case of recursion
        for(int ringIndex = 0; ringIndex < m; ringIndex++) {
            t[ringIndex][n] = 0;
        }
        
        // Filling the table from right to left columnwise (Since we need the value of keyIndex+1 in recursion which we have now in the last column)
        for(int keyIndex = n-1; keyIndex >= 0; keyIndex--) {
            for(int ringIndex = 0; ringIndex < m; ringIndex++) {
                int result = INT_MAX;
                for(int i = 0; i < m; i++) {
                    if(ring[i] == key[keyIndex]) {
                        // Number of steps to spell the current key character by rotating the ring
                        // 1 is added for step to press the center button to spell
                        int steps  = 1 + countSteps(ringIndex, i, m);

                        // Total steps to spell all the remaining key characters 
                        int totalSteps = steps + t[i][keyIndex+1];

                        // Storing the minimum steps to spell in case the current key character matches with more than 1 ring characters
                        result = min(result, totalSteps);
                    }
                }
                
                // Store the result in current t[ringIndex][keyIndex] cell
                t[ringIndex][keyIndex] = result;
            }
        }
        
        // Finally when all the cells of 't' are filled, t[0][0] entry will be containing  minimum number of steps to spell all the characters in the keyword 
        return t[0][0];
        
    }
    
    
    int findRotateSteps(string ring, string key) {
        
        int m = ring.size();
        int n = key.size();
        
        // Using recursion
        // return solve(ring, key, 0, 0, m, n);
        
        // Using Top-Down Memoization
        // int dp[101][101];
        // memset(dp, -1, sizeof(dp));     // Intitalize all values with -1
        // return solveMemo(ring, key, 0, 0, m, n, dp);
        
        // Using Bottom Up Approach
        vector<vector<int>> t(m+1, vector<int> (n+1, INT_MAX)); // Intitalize all values with INT_MAX
        return solveBottomUp(ring, key, m, n, t);
        
    }
};