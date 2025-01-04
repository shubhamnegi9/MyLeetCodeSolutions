class Solution {
public:
    // T.C. = O(2n)
    // S.C. = O(n) 
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

    // T.C. = O(2n)
    // S.C. = O(1)
    void moveZeroes2(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n && nums[i] != 0) {
            i++;
        }
        if(i < n) {
            for(int j = i+1; j < n; j++) {
                if(nums[j] != 0) {
                    swap(nums[i], nums[j]);
                    i++;
                }
            }
        }
    }

    void moveZeroes(vector<int>& nums) {
        // return moveZeroes1(nums);

        return moveZeroes2(nums);
    }
};