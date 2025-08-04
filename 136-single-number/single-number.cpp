class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n) + O(m)
    // S.C. = O(m)
    int singleNumber1(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for(int& num: nums) {
            mpp[num]++;
        }

        for(auto it: mpp) {
            if(it.second == 1) {
                return it.first;
            }
        }

        return -1;
    }

    // Optimal Approach using bit manipulation
    int singleNumber2(vector<int>& nums) {
        int XOR = 0;

        for(int& num: nums) {
            XOR ^= num;
        }

        return XOR;
    }
    
    int singleNumber(vector<int>& nums) {
        // Brute Force Approach
        // return singleNumber1(nums);

        // Optimal Approach using bit manipulation
        return singleNumber2(nums);
    }
};