class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n) + O(m), m = size of map = (n/3+1)
    // S.C. = O(m)
    int singleNumber1(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for(int& num: nums) {
            mpp[num]++;
        }

        for(auto it: mpp) {
            if(it.second == 1)
                return it.first;
        }

        return -1;
    }

    // Better Approach
    // T.C. = O(n * 32)
    // S.C. = O(1)
    int singleNumber2(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int bitIndex = 0; bitIndex < 32; bitIndex++) {
            int count = 0;
            for(int i = 0; i < n; i++) {
                // Check if bit at bitIndex is set in nums
                if(nums[i] & (1 << bitIndex)) {
                    count++;
                }
            }
            // Make bit at bitIndex as set in ans only if count leaves remainder of 1 when divided by 3
            if(count % 3 == 1) {
                ans = ans | (1 << bitIndex);    // Making bit at bitIndex as set in ans
            }
        }

        return ans;
    }

    // More Better Approach
    // T.C. = O(nlogn) + O(n/3)
    // S.C. = O(1)
    int singleNumber3(vector<int>& nums) {
        int n = nums.size();

        // Sort the numbers first to group them together
        sort(nums.begin(), nums.end());

        for(int i = 1; i < n; i+=3) {
            if(nums[i] != nums[i-1])
                return nums[i-1];
        }

        return nums[n-1];
    }

    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(1)
    int singleNumber4(vector<int>& nums) {
        int ones = 0, twos = 0;

        for(int i = 0; i < nums.size(); i++) {
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }

        return ones;
    }

    int singleNumber(vector<int>& nums) {
        // Brute Force Approach
        // return singleNumber1(nums);

        // Better Approach
        // return singleNumber2(nums);

        // More Better Approach
        // return singleNumber3(nums);

        // Optimal Approach
        return singleNumber4(nums);
    }
};