class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high) {
            int mid = (low+high)/2;

            if(nums[mid] == target) {
                return true;
            }

            // Additional condition to check in case array contains duplicates
            if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low+=1;
                mid-=1;
                continue;   // Since we need to keep moving low and high first until this condition breaks
            }

            // Left sorted half
            if(nums[low] <= nums[mid]) {
                // Check if target lies in sorted half
                if(target >= nums[low] && target <= nums[mid]) {
                    high = mid-1;   // Eliminate right half
                }
                else {
                    low = mid+1;    // Eliminate left half
                }
            }
            // Right sorted half
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

        return false;
    }
};