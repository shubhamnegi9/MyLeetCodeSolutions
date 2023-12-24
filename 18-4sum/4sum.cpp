class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        // Sort given array
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            // Skipping same nums[i] elements
            // to avoid duplicate quads
            if(i > 0 && nums[i] == nums[i-1]) 
                continue;
                
            for(int j = i+1; j < n; j++) {
                // Skipping same nums[j] elements
                // to avoid duplicate quads
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;

                int k = j+1;
                int l = n-1;

                // Iterate until k does not becomes l or cross l
                while(k < l) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if(sum < target) {
                        // Move k to next element
                        k++;
                    }
                    else if(sum > target) {
                        // Move l to previous element
                        l--;
                    }
                    else {
                        // quad found
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});

                        // Move k to next element and 
                        // l to previous element
                        k++;
                        l--;

                        /* Keep moving k to next elements
                        and l to previous elements
                        if same element found.
                        Also check the condition k < l everytime
                        to prevent overflow.
                        */
                        while(k < l && nums[k] == nums[k-1])
                            k++;
                        
                        while(k < l && nums[l] == nums[l+1])
                            l--;
                    }
                } 
            }
        }

        return ans;
    }
};