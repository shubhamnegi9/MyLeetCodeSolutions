class Solution {
public:
    // Brute Force
    // T.C. = O(n^3)
    // S.C. = O(n)
    int sumSubarrayMinsBrute(vector<int>& arr) {
        int n  = arr.size();
        long sum = 0;
        int M = 1e9+7;  // 1e9 stands for 1 × 10^9
        for(int i = 0; i < n; i++) {
            vector<int> subArr;
            for(int j = i; j < n; j++) {
                subArr.push_back(arr[j]);
                int minEle = *min_element(subArr.begin(), subArr.end());
                sum = (sum+minEle)%M;
            }
        }
        return sum;
    }

    // Better Brute
    // T.C.  = O(n^2)
    // S.C. = O(1)
    int sumSubarrayMinsBetter(vector<int>& arr) {
        int n  = arr.size();
        long sum = 0;
        int M = 1e9+7;  // 1e9 stands for 1 × 10^9
        for(int i = 0; i < n; i++) {
            int minEle = arr[i];
            for(int j = i; j < n; j++) {
                minEle = min(minEle, arr[j]);
                sum = (sum+minEle)%M;
            }
        }
        return sum;
    }
    
    // Optimal Approach 
    // T.C. = O(n) + O(n) + O(n) = O(3n) = O(n)
    // S.C. = O(n)
    vector<int> getNextSmallerToLeft(vector<int>& arr, int n) {
        /* NSL - Vector for storing indexes of the element on left hand side which are just 
        smaller than current element. If no smaller element is found on left, -1 is stored.
        */
        vector<int> NSL(n);  
        stack<int> s;

        // Filling NSL vector from 0 to n-1
        for(int i = 0; i < n; i++) {
            // If stack is empty initially, -1 is stored
            if(s.empty()) {
                NSL[i] = -1;
            }
            else {
                // Keep popping until larger(or equal) element found 
                // NOTE: (>=) sign is placed to handle corner case for duplicate elements
                while(!s.empty() && arr[s.top()] >= arr[i]) {
                    s.pop();
                }
                // Store -1 if stack becomes empty, else store top element of stack
                NSL[i] = s.empty() ? -1 : s.top();
            }
            // Finally push current index in stack
            s.push(i);
        }

        return NSL;
    }

    vector<int> getNextSmallerToRight(vector<int>& arr, int n) {
        /* NSL - Vector for storing indexes of the element on right hand side which are just 
        smaller than current element. If no smaller element is found on left, n is stored.
        */
        vector<int> NSR(n);
        stack<int> s;

        // Filling NSR vector from n-1 to 0
        for(int i = n-1; i >= 0; i--) {
            // If stack is empty initially, n is stored
            if(s.empty()) {
                NSR[i] = n;
            }
            else {
                // Keep popping until larger element found 
                while(!s.empty() && arr[s.top()] > arr[i]) {
                    s.pop();
                }
                // Store n if stack becomes empty, else store top element of stack
                NSR[i] = s.empty() ? n : s.top();
            }
            // Finally push current index in stack
            s.push(i);
        }

        return NSR;
    }

    int sumSubarrayMinsOptimal(vector<int>& arr) {
        int n = arr.size();
        int M = 1e9+7;  // 1e9 stands for 1 × 10^9

        vector<int> NSL = getNextSmallerToLeft(arr, n);
        vector<int> NSR = getNextSmallerToRight(arr, n);

        long long res = 0;
        for(int i = 0; i < n; i++) {
            // Number of subarrays on left side in which current element is minumum
            long long  leftSide = (i - NSL[i]);
            // Number of subarrays on right side in which current element is minumum
            long long  rightSide = (NSR[i] - i);
            // Total number of subarrays in which current element is minimum
            long long  ways = leftSide * rightSide;
            res = (res + (arr[i] * ways)) % M;
        }

        return res;
    }
    
    int sumSubarrayMins(vector<int>& arr) {

        // return sumSubarrayMinsBrute(arr);

        // return sumSubarrayMinsBetter(arr);

        return sumSubarrayMinsOptimal(arr);
    }
};