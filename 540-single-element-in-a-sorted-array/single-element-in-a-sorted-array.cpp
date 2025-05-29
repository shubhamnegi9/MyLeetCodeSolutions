class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n)
    // S.C. = O(1)
    int singleNonDuplicate1(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
            return nums[0];

        for(int i = 0; i < n; i++) {
            if(i == 0 && nums[i] != nums[i+1]) {
                return nums[i];
            }
            else if(i == n-1 && nums[i] != nums[i-1]) {
                return nums[i];
            }
            else {
                if(i > 0 && i < n-1 && nums[i] != nums[i-1] && nums[i] != nums[i+1]) {
                    return nums[i];
                }
            }
        }

        return -1;
    }

    // Optimal Approach
    // T.C. = O(logn)
    // S.C. = O(1)
    int singleNonDuplicate2(vector<int>& nums) {
        int n = nums.size();

        // Edge cases
        if(n == 1)
            return nums[0];
        if(nums[0] != nums[1])
            return nums[0];
        if(nums[n-1] != nums[n-2])
            return nums[n-1];
        
        int low = 1, high = n-2;

        while(low <= high) {
            int mid = low+(high-low)/2;

            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) 
                return nums[mid];
            
            // We are on left half of mid (even, odd)
            if((mid%2 == 0 && nums[mid] == nums[mid+1]) || (mid%2 == 1 && nums[mid] == nums[mid-1])) {
                low = mid+1;        // Eliminate left half
            } 
            // We are on right half of mid (odd, even)
            else {
                high = mid-1;       // Eliminate right half
            }
        }

        return -1;
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        // Brute Force Approach
        // return singleNonDuplicate1(nums);

        // Optimal Approach
        return singleNonDuplicate2(nums);
    }
};