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
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        return fourSum1(nums, target);
    }
};