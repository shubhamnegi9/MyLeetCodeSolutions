class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<vector<int>> result;

        // Sorting the given array
        // (We done sorting so that we can get next greater element together)
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i+=3) {   // Moving 'i' everytime after third element

            // Checking for nums[i], nums[i+1], nums[i+2]:
            // If the difference between smallest: nums[i] and largest: nums[i+2] is <= k,
            // then only difference between any two elements <= k

            if(nums[i+2] - nums[i] > k) {
                return {};  // return empty array
            }

            result.push_back({nums[i], nums[i+1], nums[i+2]});
        }

        return result;
    }
};