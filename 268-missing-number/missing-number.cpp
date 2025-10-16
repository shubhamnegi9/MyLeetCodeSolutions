class Solution {
public:
    // Brute Force Approach
    int missingNumber1(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());

        for(int i = 0; i <= n; i++) {
            if(st.find(i) == st.end()) {
                return i;
            }
        }

        return -1;
    }

    // Optimal Approach using sum
    int missingNumber2(vector<int>& nums) {
        int n = nums.size();
        int S = n*(n+1)/2;
        int S2 = 0;

        for(int& num: nums) {
            S2+=num;
        }

        return S - S2;
    }

    int missingNumber3(vector<int>& nums) {
        int XOR = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            XOR ^= nums[i];
            XOR ^= i;
        }
        XOR ^= n;

        return XOR;
    }
    
    int missingNumber(vector<int>& nums) {
        // Brute Force Approach
        // return missingNumber1(nums);

        // Optimal Approach using sum
        // return missingNumber2(nums);

        // Optimal Approach using XOR
        return missingNumber3(nums);
    }
};