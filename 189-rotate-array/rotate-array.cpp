class Solution {
public:
    // Brute Force Approach
    void rotate1(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        
        while(k--) {
            int temp = nums[n-1];
            for(int i = n-1; i > 0; i--) {
                nums[i] = nums[i-1];
            }
            nums[0] = temp;
        }       
    }
    
    void rotate2(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        
        ::rotate(nums.begin(), nums.begin()+n-k, nums.end());   // Since STL function name is same as given function so need to write as ::rotate()
    }
    
    void rotate(vector<int>& nums, int k) {
        // rotate1(nums, k);
        
        rotate2(nums, k);
    }
};