class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int temp = nums[i];
            nums[i] = temp * temp;
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};