class Solution {
public:
    // Brute Force Approach
    // T.C. = O(k*n)
    // S.C. = O(1)
    void rotate1(vector<int>& nums, int k, int n) {
        k = k % n;
        while(k) {
            int temp = nums.back();
            for(int i = n-1; i >= 1; i--) {
                nums[i] = nums[i-1];
            }
            nums[0] = temp;
            k--;
        }
    }

    // Better Approach
    // T.C. = O(k) + O(n-k) + O(k) = O(n+k)
    // S.C. = O(k)
    void rotate2(vector<int>& nums, int k, int n) {
        k = k % n;
        vector<int> temp(k);

        for(int i = n-k; i < n; i++) {
            temp[i-n+k] = nums[i];
        }

        for(int i = n-k-1; i >= 0; i--) {
            nums[i+k] = nums[i];
        }

        for(int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }

    // Optimal Approach
    // T.C. = O(n)+O(k)+O(n-k) = O(2n)
    // S.C. = O(1)
    void rotate3(vector<int>& nums, int k, int n) {
        k = k % n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
    
    // Using rotate STL
    void rotate4(vector<int>& nums, int k, int n) {
        k = k%n;
        ::rotate(nums.begin(), nums.begin()+n-k, nums.end());
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        // Brute Force Approach
        // return rotate1(nums, k, n);

        // Better Approach
        // return rotate2(nums, k, n);

        // Optimal Approach
        // return rotate3(nums, k, n);

        // Using rotate STL
        return rotate4(nums, k, n);
    }
};