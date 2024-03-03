class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        int result = n;
        while(low <= high) {
            int mid = (low + high)/2;
            // Can be potential candidate for lower bound
            if(nums[mid] >= target) {
                result = mid;   
                high = mid-1;   // Move high to mid-1 to find smaller lower bound index
            }
            else {
                low = mid+1;    // Move low to mid+1 to find lower bound index
            }
        }

        return result;
    }
};