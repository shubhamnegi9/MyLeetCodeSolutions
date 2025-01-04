class Solution {
public:
    // T.C. = O(n^2)
    // S.C. = O(1)
    int majorityElement1(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = i ; j < n; j++) {
                if(nums[j] == nums[i])
                    count++;
            }
            if(count > n/2)
                return nums[i];
        }

        return -1;
    }
    
    int majorityElement(vector<int>& nums) {
        return majorityElement1(nums);
    }
};