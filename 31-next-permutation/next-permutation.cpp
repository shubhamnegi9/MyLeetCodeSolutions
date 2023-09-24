class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Finding the breakpoint index
        int index = -1;
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                index = i;
                break;
            }
        }

        // If no breakpoint index exists then the given array is in decreasing order.
        // In this case reverse the array to get next greater permutation.
        if(index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find the element > element at breakpoint index 
        // on the right and swap it
        for(int i = n-1; i > index; i--) {
            if(nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }

        // Step 3: Reverse the remaining portion after breakpoint index
        reverse(nums.begin()+index+1, nums.end());
        
    }
};