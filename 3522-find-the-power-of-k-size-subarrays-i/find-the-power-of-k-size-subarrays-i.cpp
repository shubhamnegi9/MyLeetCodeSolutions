class Solution {
public:
    bool isSortedAndConsecutive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            if(nums[i-1]+1 != nums[i])
                return false;
        }    
        return true;
    }
    
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        for(int i = 0; i < n-k+1; i++) {
            int power = -1;
            vector<int> temp(nums.begin()+i, nums.begin()+i+k);
            if(isSortedAndConsecutive(temp)) {
                power = *max_element(nums.begin()+i, nums.begin()+i+k);
            }
            result.push_back(power);
        }
        return result;
    }
};