class Solution {
public:
    // Brute Force
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

    // Optimal Approach 1
    // T.C. = O(n)
    // S.C. = O(1)
    int maxProduct2(vector<int>& nums) {
        int n = nums.size();
        int maxProd = INT_MIN;
        int prefixProd = 1, suffixProd = 1;

        for(int i = 0; i < n; i++) {
            if(prefixProd == 0)
                prefixProd = 1;
            if(suffixProd == 0)
                suffixProd = 1;

            prefixProd *= nums[i];
            suffixProd *= nums[n-1-i];
            maxProd = max(maxProd, max(prefixProd, suffixProd));    // or maxProd = max({maxProd, prefixProd, suffixProd});
        }

        return maxProd;
    }

    // Optimal Approach 2
    // T.C. = O(n)
    // S.C. = O(1)
    int maxProduct3(vector<int>& nums) {
        int n = nums.size();
        int currMax = nums[0];
        int currMin = nums[0];
        int maxProd = nums[0];

        for(int i = 1; i < n; i++) {
            int temp = max({nums[i], nums[i]*currMax, nums[i]*currMin});
            currMin = min({nums[i], nums[i]*currMax, nums[i]*currMin});
            currMax = temp;
            maxProd = max(maxProd, currMax);
        }

        return maxProd;
    }

    int maxProduct(vector<int>& nums) {
        // Brute Force
        // return maxProduct1(nums);

        // Optimal Approach 1
        // return maxProduct2(nums);

        // Optimal Approach 2
        return maxProduct3(nums);
    }
};