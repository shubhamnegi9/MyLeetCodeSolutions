class Solution {
public:
    // Brute Force Approach (Will give TLE)
    // T.C. = O(n^3)*O(log(m)), m = no. of unique triplets
    // S.C. = O(m) for set for solving problem + O(m) for vector for returning answer
    vector<vector<int>> threeSum1(vector<int>& nums, int n) {
        set<vector<int>> st;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                for(int k = j+1; k < n; k++) {
                    long long sum = nums[i]+nums[j];
                    sum += nums[k];
                    if(sum == 0) {
                        vector<int> v = {nums[i], nums[j], nums[k]};
                        sort(v.begin(), v.end());
                        st.insert(v);
                    }
                }
            }
        }

        vector<vector<int>> result(st.begin(), st.end());
        return result;
    }

    // Better Approach (Will give TLE)
    // T.C. = O(n^2)*O(log(m)), m = no. of unique triplets
    // S.C. = O(m) + O(n) for sets for solving problem + O(m) for vector for returning answer
    vector<vector<int>> threeSum2(vector<int>& nums, int n) {
        set<vector<int>> st;

        for(int i = 0; i < n; i++) {
            set<long long> hashSet;
            for(int j = i+1; j < n; j++) {
                long long third = -(nums[i]+nums[j]);
                if(hashSet.find(third) != hashSet.end()) {
                    vector<int> v = {nums[i], nums[j], (int) third};
                    sort(v.begin(), v.end());
                    st.insert(v);
                }
                hashSet.insert(nums[j]);
            }
        }

        vector<vector<int>> result(st.begin(), st.end());
        return result;
    }

    // Optimal Approach 
    // T.C. = O(nlogn) for sorting + O(n^2)
    // S.C. = O(m) for vector for returning answer
    vector<vector<int>> threeSum3(vector<int>& nums, int n) {
        // vector<vector<int>> result;
        
        // sort(nums.begin(), nums.end());

        // for(int i = 0; i < n; i++) {
        //     if(i > 0 && nums[i] == nums[i-1])
        //         continue;
            
        //     int j = i+1, k = n-1;
        //     while(j < k) {
        //         long long sum = nums[i]+nums[j];
        //         sum += nums[k];

        //         if(sum < 0) {
        //             j++;
        //         } else if(sum > 0) {
        //             k--;
        //         } else {
        //             result.push_back({nums[i], nums[j], nums[k]});
        //             j++;
        //             k--;
        //         }

        //         while(j < k && nums[j] == nums[j-1]) {
        //             j++;
        //         }

        //         while(j < k && nums[k] == nums[k+1]) {
        //             k--;
        //         }
        //     }
        // }

        // return result;

        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        
        for(int i = 0; i < n; i++) {        // O(n)
            
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
            int j = i+1;
            int k = n-1;
                
            while(j < k) {                  // O(n)
                int sum = nums[i]+nums[j]+nums[k];

                if(sum < 0) {
                    j++;
                }
                else if(sum > 0) {
                    k--;
                }
                else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while(j < k && nums[j] == nums[j-1]) {
                        j++;
                    }

                    while(j < k && nums[k] == nums[k+1]) {
                        k--;
                    }
                }
            }
        }
        
        return result;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        // Brute Force Approach
        // return threeSum1(nums, n);

        // Better Approach
        // return threeSum2(nums, n);

        // Optimal Approach
        return threeSum3(nums, n);
    }
};