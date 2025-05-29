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
    
    int singleNonDuplicate(vector<int>& nums) {
        // Brute Force Approach
        return singleNonDuplicate1(nums);
    }
};