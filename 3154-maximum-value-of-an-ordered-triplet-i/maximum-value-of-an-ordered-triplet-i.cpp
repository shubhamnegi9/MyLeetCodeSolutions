class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long result = INT_MIN;
        int n = nums.size();

        for(int i = 0; i < n-2; i++) {
            for(int j = i+1; j < n-1; j++) {
                for(int k = j+1; k < n; k++) {
                    long long value = (nums[i] - nums[j]);
                    value *= nums[k];
                    result = max(result, value);
                }
            }
        }

        return (result < 0) ? 0 : result;
    }
};