class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        long long perimeter = -1;
        long long cumSum = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < cumSum) {
                perimeter = nums[i] + cumSum;
            }
            cumSum += nums[i];
        }

        return perimeter;
    }
};