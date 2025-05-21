class Solution {
public:
    
    // Brute Force Approach
    // T.C. = O(n^3)
    // S.C. = O(1)
    int subarraySum1(vector<int>& nums, int k, int n) {
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int sum = 0;
                for(int l = i; l <= j; l++) {
                    sum += nums[l];
                }
                if(sum == k)
                    count++;
            }
        }

        return count;
    }

    // Better Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    int subarraySum2(vector<int>& nums, int k, int n) {
        int count = 0;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                if(sum == k)
                    count++;
            }
        }

        return count;
    }

    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(n) for map
    int subarraySum3(vector<int>& nums, int k, int n) {
        int count = 0, sum = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            count += mpp[sum-k];
            mpp[sum]++;
        }

        return count;
    }
    
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        // Brute Force Approach
        // return subarraySum1(nums, k, n);

        // Better Approach
        // return subarraySum2(nums, k, n);

        // Optimal Approach
        return subarraySum3(nums, k, n);
    }
};