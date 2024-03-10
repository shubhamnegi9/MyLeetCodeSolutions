class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        int ans = INT_MAX;

        while(low <= high) {
            int mid = (low + high)/2;

            // Updating ans to minimum of ans and element at mid
            ans = min(ans, nums[mid]);

            // Additional condition to be added in case of duplicates
            if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low+=1;
                high-=1;
                continue;
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