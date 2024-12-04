class Solution {
public:
    int subarraySum1(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            sum = 0;
            for(int j = i; j < n; j++) {
                sum+=nums[j];
                if(sum == k)
                    count++;
            }
        }
        
        return count;
    }
    
    int subarraySum(vector<int>& nums, int k) {
        return subarraySum1(nums, k);
    }
};