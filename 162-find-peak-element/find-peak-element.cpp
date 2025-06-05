class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n)
    // S.C. = O(1)
    int findPeakElement1(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if((i == 0 || nums[i] > nums[i-1]) &&
                (i == n-1 || nums[i] > nums[i+1])) {
                    return i;
                }
        }

        return -1;
    }

    // Optimal Approach
    // T.C. = O(logn)
    // S.C. = O(1)
    int findPeakElement2(vector<int>& nums) {
        int n = nums.size();
        // Single element is peak
        if(n == 1)
            return 0;
        
        // First element is peak
        if(nums[0] > nums[1])
            return 0;
        
        // Last element is peak
        if(nums[n-1] > nums[n-2])
            return n-1;

        int low = 1, high = n-2;

        while(low <= high) {
            int mid = low+(high-low)/2;

            // Element at mid is peak
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                return mid;
            }
            // mid is on increasing slope
            else if(nums[mid] > nums[mid-1]) {
                low = mid+1;
            }
            // mid is on decreasing slope or at the inverted peak
            else {
                high = mid-1;
            }
        }

        return -1;
    }
    
    int findPeakElement(vector<int>& nums) {
        // Brute Force Approach
        // return findPeakElement1(nums);

        // Optimal Approach
        return findPeakElement2(nums);
    }
};