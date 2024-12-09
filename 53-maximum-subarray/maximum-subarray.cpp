class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;
        int n = nums.size();
        int start = 0, ansStart = -1, ansEnd = -1;
        
        for(int i = 0; i < n; i++) {
            
            if(sum == 0) {
                start = i;
            }
            
            sum+=nums[i];
            
            if(sum > maxSum) {
                maxSum = sum;
                ansStart = start;
                ansEnd = i;
            }
            
            if(sum < 0) {
                sum = 0;
            }
        }
        
        // In case it is given that subarray can also be empty
        // if(maxSum < 0) {
        //     maxSum = 0;
        // }
        
        cout << "start= " << ansStart << " " << " end= " << ansEnd << endl;
        return maxSum;
    }
};