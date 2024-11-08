class Solution {
public:
    
    // Brute Force Approach: Checking for every k value
    vector<int> getMaximumXor1(vector<int>& nums, int maximumBit) {
        int q = nums.size();
        int kMax = pow(2, maximumBit);
        vector<int> result;
        while(q) {
            int maxXOR = -1;
            int ansK = 0;
            int XOR = 0;
            for(int i = 0; i < q; i++) {
                XOR ^= nums[i];
            }
            int numsXOR = XOR;
            for(int k = 0; k < kMax; k++) {
                XOR ^= k;
                if(XOR > maxXOR) {
                    maxXOR = XOR;
                    ansK = k;
                }
                XOR = numsXOR;
            }
            result.push_back(ansK);
            q--;
        }
        
        return result;
    }
    
    // Optimal Approach using XOR properties
    //T.C : O(n)
    //S.C : O(1)
    vector<int> getMaximumXor2(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> result;
        
        // Find the total xor of given numbers
        int XOR = 0;
        for(int i = 0; i < n; i++) {
            XOR ^= nums[i];
        }
        
        // To find flip, first find the mask having all bits set to 1
        int mask = ((1 << maximumBit)-1);
        
        for(int i = 0; i < n; i++) {
            int k = XOR ^ mask;     // Flipped of the XOR
            result.push_back(k);
            XOR ^= nums[n-i-1];     // Remove last number of nums from XOR
        }
        
        return result;
    }
    
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        // Brute Force Approach
        // return getMaximumXor1(nums, maximumBit);
        
        // Optimal Approach
        return getMaximumXor2(nums, maximumBit);
    }
};