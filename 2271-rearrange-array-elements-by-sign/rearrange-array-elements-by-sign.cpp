class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int posIndex = 0, negIndex = 1;
        vector<int> res(n, 0);

        for(int i = 0; i < n; i++) {
            if(nums[i] < 0) {
                res[negIndex] = nums[i];
                negIndex += 2;
            }
            else {
                res[posIndex] = nums[i];
                posIndex += 2;
            }
        }

        return res;
    }
};