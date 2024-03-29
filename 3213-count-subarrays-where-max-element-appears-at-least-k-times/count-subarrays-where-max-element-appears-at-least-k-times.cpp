class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxEle = *max_element(nums.begin(), nums.end());
        int maxEleCount = 0;
        int i = 0, j = 0;
        long long res = 0;

        while(j < n) {
            if(nums[j] == maxEle) 
                maxEleCount++;   

            while(maxEleCount >= k) {
                res += (n-j); 

                if(nums[i] == maxEle) 
                    maxEleCount--;
                i++;
            }
            j++;
        }

        return res;
    }
};