class Solution {
public:
    // Function to find area of largest rectange in a histogram
    // Leetcode 84. Largest Rectangle in Histogram
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                int poppedIdx = st.top();
                st.pop();
                int nseIdx = i;
                int pseIdx = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, arr[poppedIdx] * (nseIdx - pseIdx - 1));
            }
            st.push(i);     // Push index not element
        }

        while(!st.empty()) {
            int poppedIdx = st.top();
            st.pop();
            int nseIdx = n;
            int pseIdx = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, arr[poppedIdx] * (nseIdx - pseIdx - 1));
        }

        return maxArea;
    }

    // T.C. = O(m*n) + O(n*2*m)
    // S.C. = O(m*n) for pSumMatrix + O(m) for stack
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();      // rows 
        int m = matrix[0].size();   // cols
        vector<vector<int>> pSumMatrix(n, vector<int>(m, 0));       // Prefix Sum Matrix of type int

        for(int j = 0; j < m; j++) {        // Iterate in columnn first and then in row
            int sum = 0;
            for(int i = 0; i < n; i++) {
                int val = matrix[i][j] - '0';   // Convert char to int
                sum += val;
                if(val == 0)        // If value in cell is 0, make sum = 0
                    sum = 0;
                pSumMatrix[i][j] = sum;
            }
        }

        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            maxArea = max(maxArea, largestRectangleArea(pSumMatrix[i]));
        }

        return maxArea;
    }
};