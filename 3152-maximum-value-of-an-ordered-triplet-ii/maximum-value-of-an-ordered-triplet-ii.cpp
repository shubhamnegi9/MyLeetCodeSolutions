class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxLefti(n, 0);
        vector<int> maxRightk(n, 0);

        for(int indx = 1; indx < n; indx++) {
            maxLefti[indx] = max(maxLefti[indx-1], nums[indx-1]);
        }

        for(int indx = n-2; indx >= 0; indx--) {
            maxRightk[indx] = max(maxRightk[indx+1], nums[indx+1]);
        }

        long long result = 0;
        for(int i = 0; i < n; i++) {
            long long val = (maxLefti[i] - nums[i]);
            val *= maxRightk[i];
            result = max(result, val);
        }

        return result;
    }
};