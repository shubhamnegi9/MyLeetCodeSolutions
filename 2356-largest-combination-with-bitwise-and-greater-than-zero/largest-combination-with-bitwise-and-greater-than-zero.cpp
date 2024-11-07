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
    
    int largestCombination(vector<int>& candidates) {
        // Approach 1
        // return largestCombination1(candidates);
        
        // Approach 2
        return largestCombination2(candidates);
    }
};