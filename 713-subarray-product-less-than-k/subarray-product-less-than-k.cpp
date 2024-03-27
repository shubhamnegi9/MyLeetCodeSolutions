class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int n = nums.size();
        int count = 0;
        int prod = 1;

        // Corner Case
        if(k <= 1)
            return 0;
        
        // Using Sliding Window Approach
        while(j < n) {
            prod *= nums[j];
            
            while(prod >= k) {
                prod /= nums[i];
                i++;
            }
            
            count += (j-i+1);  // Count of subarrays ending at 'j'
            j++;
        }
        
        return count;
    }
};