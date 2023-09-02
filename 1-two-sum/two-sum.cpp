class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> mpp;
        vector<int> res;
        for(int i = 0; i < n; i++) {
            int secondNum = target - nums[i];
            if(mpp.find(secondNum) != mpp.end()) {
                res.push_back(i);
                res.push_back(mpp[secondNum]);
            }
            mpp[nums[i]] = i;
        }
        return res;
    }
};