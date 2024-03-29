class Solution {
public:

    // Approach 1: Using Sliding Window
    // T.C. = O(n), S.C. = O(n)
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

    // Approach 2: Using Sliding Window without nested loop
    // T.C. = O(n), S.C. = O(n)
    int maxSubarrayLength2(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int i = 0, j = 0;
        int maxLen = 0;
        int culprit = 0;

        while(j < n) {

            mpp[nums[j]]++;

            if(mpp[nums[j]] == k+1) {
                culprit++;
            }

            if(culprit > 0) {
                mpp[nums[i]]--;
                if(mpp[nums[i]] == k) {
                    culprit--;
                }
                i++;
            }

            if(culprit == 0)
                maxLen = max(maxLen, j-i+1);
            j++;
        }

        return maxLen;
    }

    int maxSubarrayLength(vector<int>& nums, int k) {
        // Approach 1: Using Sliding Window
        // return maxSubarrayLength1(nums, k);

        // Approach 2: Using Sliding Window without nested loop
        return maxSubarrayLength2(nums, k);
    }
};