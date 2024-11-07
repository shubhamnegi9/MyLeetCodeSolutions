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
    
    int largestCombination(vector<int>& candidates) {
        return largestCombination1(candidates);
    }
};