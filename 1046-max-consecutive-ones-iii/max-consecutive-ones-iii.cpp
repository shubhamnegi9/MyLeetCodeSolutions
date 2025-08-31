class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    int longestOnes1(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;

        for(int i = 0; i < n; i++) {
            int zeroes = 0;     // Reset zeroes when starting point of subarray changes  
            for(int j = i; j < n; j++) {
                if(nums[j] == 0) {
                    zeroes++;
                }
                if(zeroes <= k) {
                    maxLen = max(maxLen, j-i+1);
                } else {
                    break;      // Break from further iteration as we don't want the subarrays having no. of zeros > k
                }
            }
        }
        
        return maxLen;
    }

    // Better Approach
    // T.C. = O(2n)
    // S.C. = O(1)
    int longestOnes2(vector<int>& nums, int k) {
        int l = 0, r = 0, maxLen = 0, n = nums.size(), zeroes = 0;

        while(r < n) {
            if(nums[r] == 0)
                zeroes++;
            
            while(l < r && zeroes > k) {
                if(nums[l] == 0)
                    zeroes--;
                l++;
            }

            if(zeroes <= k)
                maxLen = max(maxLen, r-l+1);
            r++;
        }

        return maxLen;
    }

    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(1)
    int longestOnes3(vector<int>& nums, int k) {
        int l = 0, r = 0, maxLen = 0, n = nums.size(), zeroes = 0;

        while(r < n) {
            if(nums[r] == 0)
                zeroes++;
            
            if(l < r && zeroes > k) {
                if(nums[l] == 0)
                    zeroes--;
                l++;
            }

            if(zeroes <= k)
                maxLen = max(maxLen, r-l+1);

            r++;
        }

        return maxLen;
    }
    
    int longestOnes(vector<int>& nums, int k) {
        // Brute Force Approach
        // return longestOnes1(nums, k);

        // Better Approach
        return longestOnes2(nums, k);

        // Optimal Approach
        // return longestOnes3(nums, k);
    }
};