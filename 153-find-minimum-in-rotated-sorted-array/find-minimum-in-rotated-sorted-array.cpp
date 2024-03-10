class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        int ans = INT_MAX;

        while(low <= high) {
            int mid = (low + high)/2;

            // Optimization:
            if(nums[low] <= nums[high]) {
                // Seach space is already sorted
                // nums[low] will give the smallest element in this search space
                ans = min(ans, nums[low]);
                break;	// break from further binary search 
            }

            // Left Sorted Half
            if(nums[low] <= nums[mid]) {
                // nums[low] contains minimum element in left sorted half
                ans = min(ans, nums[low]);	
                low = mid+1;
            }
            // Right sorted half
            else {
                // nums[mid] contains minimum element in right sorted half
                ans = min(ans, nums[mid]);	
                high = mid-1;
            }
        }

        return ans;
    }
};