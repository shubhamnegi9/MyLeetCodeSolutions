class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        /*
            Since nums contains elements from 1 till the length
            of nums, we can take vector instead of map to store
            frequency of each element 
        */
        vector<int> freq(n+1, 0);
        vector<vector<int>> res;

        for(int i = 0; i < n; i++) {
            if(freq[nums[i]] == res.size()) {
                // New row created for nums[i]
                res.push_back({});
            }
            // Element is placed in the row index equivalent
            // to its frequency so far 
            res[freq[nums[i]]].push_back(nums[i]);
            // Updating frequency of current element
            freq[nums[i]]++;
        }

        return res;
    }
};