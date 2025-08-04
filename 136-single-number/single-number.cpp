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
    
    int singleNumber(vector<int>& nums) {
        // Brute Force Approach
        return singleNumber1(nums);
    }
};