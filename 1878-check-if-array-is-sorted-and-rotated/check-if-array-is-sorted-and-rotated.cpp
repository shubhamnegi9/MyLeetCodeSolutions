class Solution {
public:
    bool isSorted(vector<int> nums) {
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i-1])
                return false;
        }    
        return true;
    }
    
    bool check(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            vector<int> copy = nums;
            rotate(copy.begin(), copy.begin()+i, copy.end());
            if(isSorted(copy))
                return true;
        }
        
        return false;
    }
};