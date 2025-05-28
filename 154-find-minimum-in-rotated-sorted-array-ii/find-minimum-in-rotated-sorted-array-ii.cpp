class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        int minEle = INT_MAX;

        while(low <= high) {
            int mid = low+(high-low)/2;

            minEle = min(minEle, nums[mid]);

            if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            if(nums[low] <= nums[mid]) {
                // Left half is sorted
                minEle = min(minEle, nums[low]);
                low = mid+1;
            } else {
                // Right half is sorted
                minEle = min(minEle, nums[mid]);
                high = mid-1;
            }
        }

        return minEle;
    }
};