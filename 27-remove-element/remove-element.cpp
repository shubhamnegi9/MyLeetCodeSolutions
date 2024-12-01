class Solution {
public:
    int removeElement1(vector<int>& nums, int val) {
        int n = nums.size();
        int count = 0;
        int i = 0;
        for(int j = 0; j < n; j++) {
            if(nums[j] != val) {
                nums[i] = nums[j];
                count++;
                i++;
            }
        }
        
        return count;
    }
    
    int removeElement(vector<int>& nums, int val) {
        return removeElement1(nums, val);
    }
};