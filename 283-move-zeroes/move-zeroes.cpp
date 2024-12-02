class Solution {
public:
    // Brute Force 
    void moveZeroes1(vector<int>& nums) {
        vector<int> nz;
        for(int num: nums) {
            if(num != 0) {
                nz.push_back(num);
            }
        }
        
        for(int i = 0; i < nz.size(); i++) {
            nums[i] = nz[i];
        }
        
        for(int i = nz.size(); i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
    
    void moveZeroes(vector<int>& nums) {
        moveZeroes1(nums);
    }
};