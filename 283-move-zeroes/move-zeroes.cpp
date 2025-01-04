class Solution {
public:
    void moveZeroes1(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0)
                temp.push_back(nums[i]);
        }

        int size = temp.size();
        for(int i = 0; i < size; i++) {
            nums[i] = temp[i];
        }
        for(int i = size; i < n; i++) {
            nums[i] = 0;
        }
    }

    void moveZeroes(vector<int>& nums) {
        return moveZeroes1(nums);
    }
};