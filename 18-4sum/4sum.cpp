class Solution {
public:
    
    vector<vector<int>> fourSum1(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st; // To store unique quadruplets

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                unordered_set<long long> hashSet; // Use long long to prevent overflow
                for (int k = j + 1; k < n; k++) {
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[k];
                    long long fourth = static_cast<long long>(target) - sum;

                    if (hashSet.find(fourth) != hashSet.end()) {
                        vector<int> quad = {nums[i], nums[j], nums[k], static_cast<int>(fourth)};
                        sort(quad.begin(), quad.end());
                        st.insert(quad);
                    }
                    hashSet.insert(nums[k]);
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
    
    vector<vector<int>> fourSum2(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            for(int j = i + 1; j < n; j++) {
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                int k = j+1;
                int l = n-1;
                while(k < l) {
                    long long sum = static_cast<long long>(nums[i])+nums[j]+nums[k]+nums[l];

                    if(sum > target) {
                        l--;
                    }
                    else if(sum < target) {
                        k++;
                    }
                    else {
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;

                        while(k < l && nums[k] == nums[k-1]) {
                            k++;
                        }
                        while(k < l && nums[l] == nums[l+1]) {
                            l--;
                        }
                    }
                }
            }
        }

        return result;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // return fourSum1(nums, target);

        return fourSum2(nums, target);
    }
};