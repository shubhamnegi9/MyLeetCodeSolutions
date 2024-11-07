class Solution {
public:
    // Approach 1: Checking the largest combination having ith bit as set using count vector
    // T.C. = O(24*n) = O(n)
    // S.C. = O(24) = O(1)
    int largestCombination1(vector<int>& candidates) {
        vector<int> count(24, 0);
        int maxSize = 0;
        for(int i = 0; i < 24; i++) {                   // O(24)
            for(int &num: candidates) {                 // O(n)
                // Check if ith bit in num is set
                if((num & (1 << i)) > 0) {     // Put brackets carefully!
                    count[i]++;
                }
            }
            maxSize = max(maxSize, count[i]);
        }
        return maxSize;
    }
    
    // Approach 2: Checking the largest combination having ith bit as set using count variable
    // T.C. = O(24*n) = O(n)
    // S.C. = O(1)
    int largestCombination2(vector<int>& candidates) {
        int maxSize = 0;
        for(int i = 0; i < 24; i++) {                   // O(24)
            int count = 0;  // Intialize count of numbers having ith bit as set as 0 for each position
            for(int &num: candidates) {                 // O(n)
                // Check if ith bit in num is set
                if((num & (1 << i)) > 0) {     // Put brackets carefully!
                    count++;
                }
            }
            maxSize = max(maxSize, count);
        }
        return maxSize;
    }
    
    // Approach 3: Using Recursion (Will give TLE)
    int solve(vector<int>& candidates, int i, int bitwiseAND, int count) {
        
        if(i == candidates.size())
            return bitwiseAND > 0 ? count : 0;
        
        // Take the current element in combination
        int take = solve(candidates, i+1, bitwiseAND & candidates[i], count+1);
        
        // Not take the current element in combination
        int notTake = solve(candidates, i+1, bitwiseAND, count);
        
        return max(take, notTake);
    }
    
    int largestCombination3(vector<int>& candidates) {
        return solve(candidates, 0, -1, 0);
    }
    
    // Approach 4: Using Top Down Memoization (Will give TLE)
    int solveMemo(vector<int>& candidates, int i, int bitwiseAND, int count, map<int, map<int, map<int, int>>> &memo) {
        
        if(i == candidates.size())
            return bitwiseAND > 0 ? count : 0;
        
        if(memo[i][bitwiseAND].find(count) != memo[i][bitwiseAND].end())
        return memo[i][bitwiseAND][count];
        
        // Take the current element in combination
        int take = solveMemo(candidates, i+1, bitwiseAND & candidates[i], count+1, memo);
        
        // Not take the current element in combination
        int notTake = solveMemo(candidates, i+1, bitwiseAND, count, memo);
        
        return memo[i][bitwiseAND][count] = max(take, notTake);
    }
    
    int largestCombination4(vector<int>& candidates) {
        // Define a nested map for memoization
        // We need to store 3 variables: i, bitwiseAND, count as key and 1 value
        map<int, map<int, map<int, int>>> memo;
        return solveMemo(candidates, 0, -1, 0, memo);
    }
    
    int largestCombination(vector<int>& candidates) {
        // Approach 1
        // return largestCombination1(candidates);
        
        // Approach 2
        return largestCombination2(candidates);
        
        // Approach 3 (Will give TLE)
        // return largestCombination3(candidates);
        
        // Approach 4 (Will give TLE)
        // return largestCombination4(candidates);
    }
};