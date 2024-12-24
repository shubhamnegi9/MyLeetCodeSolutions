class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n^3) * O(log(no. of triplets))
    // S.C. = O(no. of triplets) extra space for set + O(no. of triplets) for vector for returning result
    vector<vector<int>> threeSum1(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> tripletSet;
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                for(int k = j+1; k < n; k++) {
                    if(nums[i]+nums[j]+nums[k] == 0){
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end());
                        tripletSet.insert(triplet);
                    }
                }
            }
        }
        
        vector<vector<int>> result(tripletSet.begin(), tripletSet.end());
        return result;
    }
    
    // Better Approach
    // T.C. = O(n^2) * O(log(no. of triplets))
    // S.C. = O(n) for hashSet + O(no. of triplets) extra space for set + O(no. of triplets) for vector for returning result
    vector<vector<int>> threeSum2(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> tripletSet;
        
        for(int i = 0; i < n; i++) {
            unordered_set<int> hashSet;     // O(1)
            for(int j = i+1; j < n; j++) {
                int third = -(nums[i]+nums[j]);
                if(hashSet.find(third) != hashSet.end()) {
                    vector<int> triplet = {nums[i], nums[j], third};
                    sort(triplet.begin(), triplet.end());
                    tripletSet.insert(triplet);
                }
                hashSet.insert(nums[j]);
            }
        }
        
        vector<vector<int>> result(tripletSet.begin(), tripletSet.end());
        return result;
    }
    
    // Optimal Approach
    // T.C. = O(nlogn) for sorting + O(n^2)
    // S.C. = O(no. of triplets) for vector for returning result
    vector<vector<int>> threeSum3(vector<int>& nums) {
        int n = nums.size();
        
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
        // Brute Force Approach
        // return threeSum1(nums);
        
        // Better Approach
        // return threeSum2(nums);
        
        // Optimal Approach
        return threeSum3(nums);
    }
};