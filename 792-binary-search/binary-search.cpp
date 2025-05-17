class Solution {
public:
    // Iterative Way
    int search1(vector<int>& nums, int target, int n) {
        int low = 0, high = n-1;

        while(low <= high) {
            int mid = low + (high-low)/2;

            if(nums[mid] == target) {
                return mid;
            } else if(target > nums[mid]) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        return -1;
    }

    // Recursive Way
    int search2(vector<int>& nums, int low, int high, int target) {
        // Base case
        if(low > high)
            return -1;
        
        int mid = low + (high-low)/2;
        if(nums[mid] == target) {
            return mid;
        } else if(target > nums[mid]) {
            return search2(nums, mid+1, high, target);
        } else {
            return search2(nums, low, mid-1, target);
        }
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        // Iterative Way
        // return search1(nums, target, n);

        // Recursive Way
        return search2(nums, 0, n-1, target);
    }
};