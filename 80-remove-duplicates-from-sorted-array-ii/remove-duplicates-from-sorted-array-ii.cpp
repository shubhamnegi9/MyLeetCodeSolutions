class Solution {
public:
    int removeDuplicates1(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        int count = 1;
        for(int j = 1; j < n; j++) {
            if(nums[j] == nums[j-1]) {
                count++;
            } else {
                count = 1;
            }
            
            if(count <= 2) {
               nums[i] = nums[j];
                i++;
            }
        }
        
        return i;
    }
    
    int removeDuplicates(vector<int>& nums) {
        return removeDuplicates1(nums);
    }
};