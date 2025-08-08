class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n) + O(m), m = size of map = n/2+1
    // S.C. = O(m)
    vector<int> singleNumber1(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for(int& num: nums) {
            mpp[num]++;
        }

        vector<int> ans;
        for(auto it: mpp) {
            if(it.second == 1) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }

    // Optimal Approach
    // T.C. = O(2n)
    // S.C. = O(1)
    vector<int> singleNumber2(vector<int>& nums) {
        long XORR = 0;

        for(int& num: nums) {
            XORR ^= num;
        }

        int rightMost = (XORR & (XORR-1)) ^ XORR;

        int b1 = 0, b2 = 0;
        for(int& num: nums) {
            if(num & rightMost) {
                b1 ^= num;
            } else {
                b2 ^= num;
            }
        }

        return {b1, b2};
    }
    
    vector<int> singleNumber(vector<int>& nums) {
        // Brute Force Approach
        return singleNumber1(nums);

        // Optimal Approach
        // return singleNumber2(nums);
    }
};