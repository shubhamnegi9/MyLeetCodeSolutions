class Solution {
public:
    /*
        Same approach as LC: 560 problem
    */
    int findMaxLength(vector<int>& nums) {
        map<int, int> mpp;
        int cumSum = 0;
        mpp.insert({0, -1});
        int maxLen = 0;
        for(int i = 0; i < nums.size(); i++) {
            // Adding -1 to cumSum in case of 0 
            // Once cumSum == 0, we will get equal number of 0s and 1s in subarray
            // So we need to find longest length of subarray with sum = 0
            cumSum += (nums[i]==0) ? -1 : nums[i];
            if(mpp.find(cumSum) != mpp.end()) {
                int len = i - mpp[cumSum];
                maxLen = max(maxLen, len);
            }
            else {
                // Updating value in map in else case only otherwise we will not get longest length sum
                mpp[cumSum] = i;
            }
        }

        return maxLen;
    }
};