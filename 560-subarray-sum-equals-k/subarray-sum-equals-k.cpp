class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    int subarraySum1(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum+=nums[j];
                if(sum == k)
                    count++;
            }
        }
        
        return count;
    }
    
    // Optimal Approach using hashing
    // T.C. = O(n)
    // S.C. = O(n)
    int subarraySum2(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> prefixSumMap;
        // Adding entry <0, 1> in map initially
        prefixSumMap[0] = 1;
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            sum+=nums[i];
            count+=prefixSumMap[sum-k];
            prefixSumMap[sum]++;
        }
        
        return count;
    }
    
    int subarraySum(vector<int>& nums, int k) {
        // Brute Force Approach
        // return subarraySum1(nums, k);
        
        // Optimal Approach using hashing
        return subarraySum2(nums, k);
    }
};