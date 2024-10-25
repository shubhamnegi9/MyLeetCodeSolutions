class Solution {
public:
    
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    vector<int> twoSum1(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result;
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                if(nums[i] + nums[j] == target) {
                    result = {i, j};
                    break;
                }
            }
        }
        
        return result;
    }
    
    // Better Approach
    // T.C. = O(n) for loop + O(1) for find/insert in unordered map
    //      = O(n)
    // S.C. = O(n) for map
    vector<int> twoSum2(vector<int> &nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            int remaining = target - nums[i];
            if(mp.find(remaining) != mp.end()){     // Element is present in map
                return {mp[remaining], i};
            }
            mp[nums[i]] = i;
        }
        
        return {};
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        // Brute Force Approach
        // return twoSum1(nums, target);
        
        // Better Approach
        return twoSum2(nums, target);
    }
};