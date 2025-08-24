class Solution {
public:
    vector<int> findNSE(vector<int>& heights, int n) {
        vector<int> nseIdx(n, n);   // In case of no NSE, index will be n
        stack<int> st;

        for(int i = n-1; i >= 0; i--) {             // In case of NSE, iterate from n-1 to 0
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nseIdx[i] = st.empty() ? n : st.top();      // In case of no NSE, index will be n
            st.push(i);     // Push index not element
        }

        return nseIdx;
    }

    vector<int> findPSE(vector<int>& heights, int n) {
        vector<int> pseIdx(n, -1);   // In case of no PSE, index will be -1
        stack<int> st;

        for(int i = 0; i < n; i++) {             // In case of PSE, iterate from 0 to n-1
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            pseIdx[i] = st.empty() ? -1 : st.top();     // In case of no PSE, index will be -1
            st.push(i);     // Push index not element
        }

        return pseIdx;
    }

    // Brute Force Approach
    // T.C. = O(2n) for finding PSE + O(2n) for finding NSE + O(n) = O(5n)
    // S.C. = O(2n) for stack and pseIdx + O(2n) for stack and nseIdx = O(4n)
    int largestRectangleArea1(vector<int>& heights) {
        int n = heights.size();
        vector<int> nseIdx = findNSE(heights, n);
        vector<int> pseIdx = findPSE(heights, n);

        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            maxArea = max(maxArea, heights[i] * (nseIdx[i] - pseIdx[i] - 1));
        }

        return maxArea;
    }

    // Optimal Approach
    // T.C. = O(n) for traversing in array + O(n) for all stack operations = O(2n)
    // S.C. = O(n) for stack 
    int largestRectangleArea2(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            // Pop the elements from stack only when element at top of stack is greater (not equal) than current element 
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int poppedIdx = st.top();
                st.pop();

                // Find NSE and PSE indices and area for the popped elements only
                int nseIdx = i;
                int pseIdx = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, heights[poppedIdx] * (nseIdx - pseIdx - 1));
            }
            st.push(i);     // Push index not element
        }

        while(!st.empty()) {
            int poppedIdx = st.top();
            st.pop();

            int nseIdx = n;     // NSE index for remainging elements in stack will always be n
            int pseIdx = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, heights[poppedIdx] * (nseIdx - pseIdx - 1));
        }

        return maxArea;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        // Brute Force Approach
        // return largestRectangleArea1(heights);

        // Optimal Approach
        return largestRectangleArea2(heights);
    }
};