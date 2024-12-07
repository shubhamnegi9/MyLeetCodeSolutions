class Solution {
public:
    
    bool isPossible(vector<int> nums, int mid, int maxOps) {
        int totalOps = 0;
        for(int& num: nums) {
            int ops = num / mid;
            if(num % mid == 0)
                ops-=1;
            totalOps+=ops;
        }
        
        return totalOps <= maxOps;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        int result = r;
        
        while(l <= r) {
            int mid = l+(r-l)/2;
            
            if(isPossible(nums, mid, maxOperations)) {
                result = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        
        return result;
    }
};