class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        if(nums.back() > nums.front())
            count++;
        
        for(int i = 0; i < n-1; i++) {
            if(nums[i] > nums[i+1])
                count++;
        }
        
        return (count <= 1);
    }
};