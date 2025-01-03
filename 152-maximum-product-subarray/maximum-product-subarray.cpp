class Solution {
public:
    // T.C. = O(n^2)
    // S.C. = O(1)
    int maxProduct1(vector<int>& nums) {
        int n = nums.size();
        int maxProd = INT_MIN;
        for(int i = 0; i < n; i++) {
            int prod = 1;
            for(int j = i; j < n; j++) {
                prod *= nums[j];
                maxProd = max(maxProd, prod);
            }
        }
        return maxProd;
    }
    
    int maxProduct(vector<int>& nums) {
        return maxProduct1(nums);
    }
};