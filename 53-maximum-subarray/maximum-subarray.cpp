class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxSum = INT_MIN;
        int start = 0, end = 0;

        for(int i = 0; i < n; i++) {
            if(sum < 0) {
                sum = 0; 
                start = i;
            }
            sum += nums[i];
            if(sum > maxSum) {
                maxSum = sum;
                end = i;
            }
        }
        cout << "Start Index: " << start << endl;
        cout << "End Index: " << end << endl;

        return maxSum;
    }
};