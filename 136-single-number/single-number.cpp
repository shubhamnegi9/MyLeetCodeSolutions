class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int XOR = 0;
        for(int ele: nums) {
            XOR ^= ele;
        }
        
        return XOR;
    }
};