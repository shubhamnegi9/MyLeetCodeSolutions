class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    vector<int> twoSum1(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j)
                    continue;
                if(nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {-1, -1};
    }

    // Better Brute Force 
    // T.C. = O(n^2)
    // S.C. = O(1)
    vector<int> twoSum2(vector<int>& nums, int target) {
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
    
    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(n)
    vector<int> twoSum3(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        for(int i = 0; i < n; i++) {
            int num = target - nums[i];
            if(mpp.find(num) != mpp.end()) {
                return {mpp[num], i};
            }
            mpp[nums[i]] = i;
        }

        return {-1, -1};
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        // Brute Force Approach
        // return twoSum1(nums, target);

        // Better Brute Force 
        // return twoSum2(nums, target);

        // Optimal Approach
        return twoSum3(nums, target);
    }
};