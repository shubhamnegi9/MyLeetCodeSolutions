class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    int trap1(vector<int>& height, int n) {
        int sum = 0;

        for(int i = 1; i < n-1; i++) {      // Water will be only trapped from index 1 to (n-2)
            int leftMax = 0;
            for(int j = 0; j < i; j++) {
                leftMax = max(leftMax, height[j]);
            }
            int rightMax = 0;
            for(int j = i+1; j < n; j++) {
                rightMax = max(rightMax, height[j]);
            }

            if(leftMax > height[i] && rightMax > height[i])
                sum += min(leftMax, rightMax) - height[i];
        }

        return sum;
    }

    // Better Approach using prefixMax and suffixMax array
    // T.C = O(3n)
    // S.C. = O(2n)
    int trap2(vector<int>& height, int n) {
        int sum = 0;
        vector<int> prefixMax(n);
        vector<int> suffixMax(n);

        prefixMax[0] = height[0];
        for(int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i-1], height[i]);
        }

        suffixMax[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i+1], height[i]);
        }

        for(int i = 0; i < n; i++) {
            int leftMax = prefixMax[i];
            int rightMax = suffixMax[i];

            if(leftMax > height[i] && rightMax > height[i]) {
                sum += min(leftMax, rightMax) - height[i];
            }
        }

        return sum;
    }

    // Better Approach using only suffixMax array
    // T.C = O(2n)
    // S.C. = O(n)
    int trap3(vector<int>& height, int n) {
        int sum = 0;
        vector<int> suffixMax(n);

        suffixMax[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i+1], height[i]);
        }

        int leftMax = 0;
        for(int i = 0; i < n; i++) {
            leftMax = max(leftMax, height[i]);
            int rightMax = suffixMax[i];

            if(leftMax > height[i] && rightMax > height[i]) {
                sum += min(leftMax, rightMax) - height[i];
            }
        }

        return sum;
    }
    
    
    int trap(vector<int>& height) {
        int n = height.size();

        // Brute Force Approach
        // return trap1(height, n);

        // Better Approach using prefixMax and suffixMax array
        return trap2(height, n);

        // Better Approach using only suffixMax array 
        // return trap3(height, n);

    }
};