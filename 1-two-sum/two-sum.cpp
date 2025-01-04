class Solution {
public:
    // T.C. = O(n^2)
    // S.C. = O(1)
    vector<int> twoSum1(vector<int>& nums, int target) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {-1, -1};
    }

    // T.C. = O(n)
    // S.C. = O(1)
    vector<int> twoSum2(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            if(mp.find(target-nums[i]) != mp.end()) {
                return {mp[target-nums[i]], i};
            }
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        // return twoSum1(nums, target);

        return twoSum2(nums, target);
    }
};