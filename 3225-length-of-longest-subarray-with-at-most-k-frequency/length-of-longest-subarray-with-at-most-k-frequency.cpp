class Solution {
public:

    // Approach 1: Using Sliding Window
    int maxSubarrayLength1(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int i = 0, j = 0;
        int maxLen = 0;

        while(j < n) {

            mpp[nums[j]]++;

            while(mpp[nums[j]] > k) {
                mpp[nums[i]]--;
                i++;
            }

            maxLen = max(maxLen, j-i+1);
            j++;
        }

        return maxLen;
    }

    int maxSubarrayLength(vector<int>& nums, int k) {
        // Approach 1: Using Sliding Window
        return maxSubarrayLength1(nums, k);
    }
};