class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int preSum = 0;
        unordered_map<int, int> prefixSumMap;
        // Initially storing <0, 1> in hashmap
        prefixSumMap[0] = 1;
        for(int i = 0; i < n; i++) {
            preSum += nums[i];
            // If (preSum - k) is present in prefixSumMap 
            if(prefixSumMap.find(preSum - k) != prefixSumMap.end()) {
                count += prefixSumMap[preSum - k];
            }
            prefixSumMap[preSum]++;
        }
        return count;
    }
};