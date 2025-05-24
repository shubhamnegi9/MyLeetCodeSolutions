class Solution {
public:
    // Better Approach
    // T.C. = O(n^3)*O(m), m = no. of unique quards
    // S.C. = O(m) for set + O(n) for hashSet + O(m) for result vector
    vector<vector<int>> fourSum1(vector<int>& nums, int target, int n) {
        set<vector<int>> st;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                unordered_set<long long> hashSet;
                for(int k = j+1; k < n; k++) {
                    long long sum = static_cast<long long>(nums[i])+nums[j]+nums[k];
                    long long fourth = static_cast<long long>(target) - sum;
                    if(hashSet.find(fourth) != hashSet.end()) {
                        vector<int> v = {nums[i], nums[j], nums[k], static_cast<int>(fourth)};
                        sort(v.begin(), v.end());
                        st.insert(v);
                    }
                    hashSet.insert(nums[k]);
                }
            }
        }

        vector<vector<int>> result(st.begin(),st.end());
        return result;
    }
    
    // Optimal Approach
    // T.C. = O(nlogn) + O(n^2)*O(n)
    // S.C. = O(m) for result vector
    vector<vector<int>> fourSum2(vector<int>& nums, int target, int n) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            for(int j = i+1; j < n; j++) {
                if(j != i+1 && nums[j] == nums[j-1])
                    continue;
                
                int k = j+1, l = n-1;

                while(k < l) {
                    long long sum = static_cast<long long>(nums[i])+nums[j]+nums[k]+nums[l];
                    if(sum < target) 
                        k++;
                    else if(sum > target) 
                        l--;
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
        int n = nums.size();

        // Better Approach
        // return fourSum1(nums, target, n);

        // Optimal Approach
        return fourSum2(nums, target, n);
    }
};