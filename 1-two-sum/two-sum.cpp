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
    vector<int> twoSum(vector<int>& nums, int target) {
        return twoSum1(nums, target);
    }
};