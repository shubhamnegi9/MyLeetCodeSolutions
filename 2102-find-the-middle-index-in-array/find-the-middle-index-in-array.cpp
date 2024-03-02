class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int leftSum = 0;
        
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int rightSum = 0;
            // Finding rightSum ahead of current index
            if(i < n-1) {
                for(int j = i+1; j < n; j++) {
                    rightSum += nums[j];
                }
            }
            if(leftSum == rightSum)
                return i;
            // Save current element to leftSum before moving ahead
            leftSum+=nums[i];
        }
        return -1;
    }
};