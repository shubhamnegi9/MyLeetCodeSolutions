class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*
            Using Sorting:

            if(nums.size() == 2) {
                return (nums[0]-1) * (nums[1]-1);
            }
            else {
                // Sorting in descending order
                sort(nums.begin(), nums.end(), greater<int>());
                return (nums[0]-1) * (nums[1]-1);
            }

            Time Complexity = O(n^2)
        */

        int largest = 0, slargest = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > largest) {
                slargest = largest;
                largest = nums[i];
            }
            else {
                slargest = max(slargest, nums[i]);
            }
        }
        return (largest-1) * (slargest-1);

        // Time Complexity = O(n)
    }
};