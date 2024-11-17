class Solution {
public:
    // T.C. = O(n^2)
    // S.C. = O(1)
    int missingNumber1(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i <= n; i++) {
            int found = 0;
            for(int j = 0; j < n; j++) {
                if(nums[j] == i) {
                    found = 1;
                    break;
                }
            }
            if(found == 0)
                return i;
        }
        return -1;
    }
    int missingNumber(vector<int>& nums) {
        return missingNumber1(nums);
    }
};