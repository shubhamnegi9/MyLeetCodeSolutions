class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n)
    // S.C. = O(1)
    int findPeakElement1(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if((i == 0 || nums[i] > nums[i-1]) &&
                (i == n-1 || nums[i] > nums[i+1])) {
                    return i;
                }
        }

        return -1;
    }
    
    int findPeakElement(vector<int>& nums) {
        // Brute Force Approach
        return findPeakElement1(nums);
    }
};