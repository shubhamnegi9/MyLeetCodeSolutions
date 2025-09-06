class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    int numberOfSubarrays1(vector<int>& nums, int k) {
        int n = nums.size(), count = 0;

        for(int i = 0; i < n; i++) {
            int oddCount = 0;
            for(int j = i; j < n; j++) {
                if(nums[j] % 2) {
                    oddCount++;
                }

                if(oddCount == k) {
                    count++;
                } else if(oddCount > k){
                    break;
                }
            }
        }

        return count;
    }

    int countSubarraysAtmostSum(vector<int>& nums, int k) {
        // Edge case
        if(k < 0) 
            return 0;
        
        int n = nums.size(), l = 0, r = 0, count = 0, sum = 0;

        while(r < n) {
            
            sum += (nums[r] % 2);      // Mod with 2 to convert to 1 if odd and 0 if even

            while(sum > k) {
                sum -= (nums[l] % 2);   // Mod with 2 to convert to 1 if odd and 0 if even
                l++;
            }

            if(sum <= k) {
                count += (r-l+1);       // Increase count by size of window
            }

            r++;
        }

        return count;
    }

    // Optimal Approach
    // T.C. = O(2*2n)
    // S.C. = O(1)
    int numberOfSubarrays2(vector<int>& nums, int k) {
        return countSubarraysAtmostSum(nums, k) - countSubarraysAtmostSum(nums, k-1);
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        // Brute Force Approach
        // return numberOfSubarrays1(nums, k);

        // Optimal Approach
        return numberOfSubarrays2(nums, k);
    }
};