class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int n = nums.size();
        long long sum = 0;
        long long maxSum = 0;
        unordered_set<int> st;  // For tracking duplicate elements
        
        while(j < n) {
            
            // Keep shrinking the window until duplicate element is removed from window
            while(st.find(nums[j]) != st.end()) {
                sum-=nums[i];
                st.erase(nums[i]);
                i++;
            }
            
            // Add only unique elements in window
            sum+=nums[j];
            st.insert(nums[j]);   
            
            // Update maxSum once k size window is found
            if(j-i+1 == k) {
                maxSum = max(maxSum, sum);
                
                // Shrink the window
                sum-=nums[i];
                st.erase(nums[i]);
                i++;
            }
            
            j++;
        }
        
        return maxSum;
    }
};