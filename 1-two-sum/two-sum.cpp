class Solution {
public:
    
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    vector<int> twoSum1(vector<int>& nums,  int target) {
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
    
    vector<int> twoSum(vector<int>& nums, int target) {
        // Brute Force Approach
        return twoSum1(nums, target);
    }
};