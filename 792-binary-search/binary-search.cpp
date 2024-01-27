class Solution {
public:
    int searchBs(vector<int> &nums, int low, int high, int target) {
        // Base Case
        if(low > high)
            return -1;
        
        int mid = (low + high)/2;

        if(nums[mid] == target)
            return mid;
        else if(target > nums[mid]) {
            return searchBs(nums, mid+1, high, target);
        }
        else {
            return searchBs(nums, low, mid-1, target);
        }
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return searchBs(nums, 0, n-1, target);
    }
};