class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> triplets;

        // Sort given array
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            // Skipping same nums[i] elements
            // to avoid duplicate triplets
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
            int j = i+1;
            int k = n-1;

            // Iterate until j does not becomes k or cross k 
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if(sum < 0) {
                    // Move j to next element
                    j++;
                }
                else if(sum > 0) {
                    // Move k to previous element
                    k--;
                }
                else {
                    // triplet found
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    triplets.push_back(temp);

                    // Move j to next element and 
                    // k to previous element
                    j++;
                    k--;

                    /* Keep moving j to next elements
                    and k to previous elements
                    if same element found.
                    Also check the condition j < k everytime
                    to prevent overflow.
                    */
                    while(j < k && nums[j] == nums[j-1]) {
                        j++;
                    }

                    while(j < k && nums[k] == nums[k+1]) {
                        k--;
                    }
                }
            }
        }
        return triplets;
    }
};