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
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Brute Force Approach
        // return numSubarraysWithSum1(nums, goal);

        // Better Approach
        return numSubarraysWithSum2(nums, goal);
    }
};