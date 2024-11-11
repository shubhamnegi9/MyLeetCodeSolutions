class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n*k) = O(n^2)
    // S.C. = O(1)
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
    
    // Better Approach
    // T.C. = O(n+k) = O(n+n) = O(2n)
    // S.C. = O(k)
    void rotate2(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> temp(k, 0);
        
        // Place last 'k' elements from nums in temp
        for(int i = n-k; i < n; i++) {
            temp[i-(n-k)] = nums[i];
        }
        
        // Shift first 'n-k' elements to right by k places
        for(int i = n-k-1; i >= 0; i--) {
            nums[i+k] = nums[i];
        }
        
        // Place first 'k' elements from temp back in nums
        for(int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
    
    // Optimal Approach
    // T.C. = O(n+k) = O(n+n) = O(n)
    // S.C. = O(1)
    void rotate3(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        
        reverse(nums.begin(), nums.end());
        
        reverse(nums.begin(), nums.begin()+k);
        
        reverse(nums.begin()+k, nums.end());
    }
    
    // Using rotate() STL function
    // T.C. = O(n)
    // S.C. = O(1)
    void rotate4(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        
        ::rotate(nums.begin(), nums.begin()+n-k, nums.end());   // Since STL function name is same as given function so need to write as ::rotate()
    }
    
    void rotate(vector<int>& nums, int k) {
        // Brute Force Approach
        // rotate1(nums, k);
        
        // Better Approach
        // rotate2(nums, k);
        
        // Optimal Approach
        rotate3(nums, k);
        
        // Using rotate() STL function
        // rotate4(nums, k);
    }
};