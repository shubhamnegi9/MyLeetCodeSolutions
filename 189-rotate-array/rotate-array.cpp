class Solution {
public:
    // T.C. = O(n*k)
    // S.C. = O(1)
    void rotate1(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;

        while(k--) {
            int temp = nums[n-1];
            for(int i = n-1; i > 0; i--) {
                nums[i] = nums[i-1];
            }
            nums[0] = temp;
        }
    }

    // T.C. = O(k) + O(n-k) + O(k) = O(n+k)
    // S.C. = O(k)
    void rotate2(vector<int>& nums, int k) {
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
    
    void rotate(vector<int>& nums, int k) {
        // return rotate1(nums, k);

        return rotate2(nums, k);
    }
};