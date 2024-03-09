class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;

        while(low <= high) {
            int mid = (low + high)/2;

            if(nums[mid] == target) {
                return mid;
            }

            // Left Sorted
            if(nums[low] <= nums[mid]) {
                // Check if target lies in sorted half
                if(target >= nums[low] && target <= nums[mid]) {
                    high = mid-1;   // Eliminate right half
                }
                else {
                    low = mid+1;    // Eliminate left half
                }
            }
            // Right sorted
            else {
                // Check if target lies in sorted half
                if(target >= nums[mid] && target <= nums[high]) {
                    low = mid+1;    // Eliminate left half
                }
                else {
                    high = mid-1;   // Eliminate right half
                }
            }
        }

        return -1;
    }
};