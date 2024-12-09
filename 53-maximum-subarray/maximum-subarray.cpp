class Solution {
public:
    // Brute Force Aproach
    // T.C. = O(n^2)
    // S.C. = O(1)
    int maxSubArray1(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(long j = i; j < n; j++) {
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }
        
        return maxSum;
    }
    
    // Optimal Approach using Kadane's Algo
    // T.C. = O(n)
    // S.C. = O(1)
    int maxSubArray2(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxSum = INT_MIN;
        for(int i = 0; i < n; i++) {
            sum+=nums[i];
            maxSum = max(maxSum, sum);
            if(sum < 0)
                sum=  0;
        }
        
        return maxSum;
    }
    
    int maxSubArray(vector<int>& nums) {
        // Brute Force Aproach
        // return maxSubArray1(nums);
        
        // Optimal Approach using Kadane's Algo
        return maxSubArray2(nums);
    }
};