class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    int numSubarraysWithSum1(vector<int>& nums, int goal) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                if(sum == goal) {
                    count++;
                } else if(sum > goal) {
                    break;
                }
            }
        }
        
        return count;
    }

    // Better Approach
    // T.C. = O(n)
    // S.C. = O(n) for unordered map
    int numSubarraysWithSum2(vector<int>& nums, int goal) {
        int n = nums.size(), count = 0, preSum = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;     // Edge case: For empty subarray, store its count as 1 in hashmap

        for(int i = 0; i < n; i++) {
            preSum += nums[i];
            if(mpp.find(preSum-goal) != mpp.end()) {    // Instead of finding goal, we find (preSum-goal) in hashmap
                count += mpp[preSum-goal];
            }
            mpp[preSum]++;
        }

        return count;
    }

    int countSubarraysAtmostSum(vector<int>& nums, int goal) {
        // Egde case
        if(goal < 0) {
            return 0;
        }

        int n = nums.size(), l = 0, r = 0, sum = 0, count = 0;

        while(r < n) {
            sum += nums[r];

            while(sum > goal) {
                sum -= nums[l];
                l++;
            }
            if(sum <= goal) {
                count += (r-l+1);   // Increase count by size of valid window
            }
            r++;
        }

        return count;
    }

    // Optimal Approach
    // T.C. = O(2*2n)
    // S.C. = O(1)
    int numSubarraysWithSum3(vector<int>& nums, int goal) {
        return countSubarraysAtmostSum(nums, goal) - countSubarraysAtmostSum(nums, goal-1);
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Brute Force Approach
        // return numSubarraysWithSum1(nums, goal);

        // Better Approach
        // return numSubarraysWithSum2(nums, goal);

        // Optimal Approach
        return numSubarraysWithSum3(nums, goal);
    }
};