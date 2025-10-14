class Solution {
public:
    void rotate1(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;

        vector<int> temp;

        for(int i = n-k; i < n; i++) {
            temp.push_back(nums[i]);
        }

        for(int i = n-k-1; i >= 0; i--) {
            nums[i+k] = nums[i];
        }

        for(int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
    
    void rotate2(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
    
    void rotate(vector<int>& nums, int k) {
        // Better Approach
        // rotate1(nums, k);

        // Optimal Approach
        rotate2(nums, k);
    }
};