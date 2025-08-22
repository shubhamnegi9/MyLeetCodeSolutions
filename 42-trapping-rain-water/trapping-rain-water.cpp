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

    // Better Approach using stack
    // T.C. = O(n) for tarversing in array + O(n) for popping n elements from stack in worst case
    // S.C. = O(n) for stack
    int trap4(vector<int>& height, int n) {
        int sum = 0;
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && height[i] > height[st.top()]) {    // Maintaining monotonic decreasing stack
                int poppedIdx = st.top();   // Storing index of popped building to find its height later
                st.pop();

                if(st.empty()) {    
                    break;  // There was no taller building on left of popped building, so no water will be trapped over popped building 
                }

                /* Otherwise if there are elements in stack, then the top element of stack will be a taller building on left of popped building (Since we are maintaining monotonic decreasing stack). And current ith building will be a taller building on right of popped building. So water will be trapped over popped building */

                // Calculating distance between two taller buildings on left and right
                int distance = i - st.top() - 1;   

                // Calculating water trapped over popped building and adding to sum
                sum += (min(height[st.top()], height[i]) - height[poppedIdx]) * distance;

            }

            st.push(i);     // Push index not height 
        }

        return sum;
    }

    // Optimal Approach using 2 pointer 
    // (by comparing heights of buildings)
    int trap5(vector<int>& height, int n) {
        int i = 0, j = n-1;
        int leftMax = 0, rightMax = 0;
        int sum = 0;

        while(i < j) {
            if(height[i] <= height[j]) {
                if(height[i] < leftMax) {
                    sum += (leftMax - height[i]);   // Amount of water above current ith building
                } else {    
                    leftMax = height[i];            // Update leftMax
                }
                i++;
            } else {
                if(height[j] < rightMax) {
                    sum += (rightMax - height[j]);  // Amount of water above current ith building
                } else { 
                    rightMax = height[j];           // Update rightMax
                }
                j--;
            }
        }

        return sum;
    }


    int trap6(vector<int>& height, int n) {
        int i = 1, j = n-2;
        int leftMax = height[0], rightMax = height[n-1];
        int sum = 0;

        while(i <= j) {
            if(leftMax <= rightMax) {
                if(height[i] < leftMax) {
                    sum += (leftMax - height[i]);   // Amount of water above current ith building
                } else {    
                    leftMax = height[i];            // Update leftMax
                }
                i++;
            } else {
                if(height[j] < rightMax) {
                    sum += (rightMax - height[j]);  // Amount of water above current ith building
                } else { 
                    rightMax = height[j];           // Update rightMax
                }
                j--;
            }
        }

        return sum;
    }
    
    int trap(vector<int>& height) {
        int n = height.size();

        // Brute Force Approach
        // return trap1(height, n);

        // Better Approach using prefixMax and suffixMax array
        // return trap2(height, n);

        // Better Approach using only suffixMax array 
        // return trap3(height, n);

        // Better Approach using stack
        // return trap4(height, n);

        // Optimal Approach using 2 pointer 
        // (by comparing heights of buildings)
        return trap5(height, n);

        // return trap6(height, n);
    }
};