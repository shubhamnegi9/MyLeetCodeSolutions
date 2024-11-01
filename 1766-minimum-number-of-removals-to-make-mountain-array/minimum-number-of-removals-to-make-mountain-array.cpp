class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n, 1);
        vector<int> LDS(n, 1);
        
        // LIS[i] -> Length of Longest Increasing Subsequence ending at index i
        // LDS[i] -> Length of Longest Decreasing Subsequence starting at index i
        
        // Finding length of LIS at every index
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    LIS[i] = max(LIS[i], LIS[j]+1);
                }
            }
        }
        
        // Finding length of LDS at every index
        for(int i = n-1; i >= 0; i--) {
            for(int j = i+1; j < n; j++) {
                if(nums[i] > nums[j]) {
                    LDS[i] = max(LDS[i], LDS[j]+1);
                }
            }
        }
         
        int minRemovals = n;    // In worst case we can remove all elements
        for(int i = 1; i < n; i++) {    // Treat each element as peak element of mountain array and finding removals
            if(LIS[i] > 1 && LDS[i] > 1)    // Min length of mountain array >= 3 only if LIS[i] > 1 && LDS[i] > 1
                minRemovals = min(minRemovals, n - LIS[i] - LDS[i] + 1);
        }
        
        return minRemovals;
    }
};