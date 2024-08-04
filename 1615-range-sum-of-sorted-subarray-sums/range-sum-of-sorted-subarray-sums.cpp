class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> subarraySum;
        long M = pow(10,9)+7;       // OR, long M = 1e9+7;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum+=nums[j];
                subarraySum.push_back(sum);
            }
        }
        sort(subarraySum.begin(), subarraySum.end());
        long long res = 0;
        for(int i = left-1; i <= right-1; i++) {
            res = (res % M) + (subarraySum[i] % M);
        }
        
        return (int) res;
    }
};