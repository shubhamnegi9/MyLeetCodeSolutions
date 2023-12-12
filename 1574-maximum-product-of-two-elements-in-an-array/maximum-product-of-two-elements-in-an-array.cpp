class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 2) {
            return (nums[0]-1) * (nums[1]-1);
        }
        else {
            // Sorting in descending order
            sort(nums.begin(), nums.end(), greater<int>());
            return (nums[0]-1) * (nums[1]-1);
        }
    }
};