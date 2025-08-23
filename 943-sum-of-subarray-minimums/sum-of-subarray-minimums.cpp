class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n^3)
    // S.C. = O(n) for subArr
    int sumSubarrayMins1(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int mod = 1e9+7;    // 1e9 stands for 1 × 10^9

        for(int i = 0; i < n; i++) {
            vector<int> subArr;
            for(int j = i; j < n; j++) {
                subArr.push_back(arr[j]);
                int minEle = *min_element(subArr.begin(), subArr.end());
                sum = (sum + minEle) % mod;
            }
        }

        return sum;
    }

    // Better Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1) 
    int sumSubarrayMins2(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int mod = 1e9+7;    // 1e9 stands for 1 × 10^9

        for(int i = 0; i < n; i++) {
            int minEle = arr[i];
            for(int j = i; j < n; j++) {
                minEle = min(minEle, arr[j]);
                sum = (sum + minEle) % mod;
            }
        }

        return sum;
    }
    
    // Optimal Approach
    vector<int> findNSE(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> nseIdx(n, n);       // In case of no NSE, value will be n

        for(int i = n-1; i >= 0; i--) {
        // We need to find next smaller element, so if we get greater or equal element on top of stack, remove it
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            nseIdx[i] = st.empty() ? n : st.top();       // In case of no NSE, value will be n

            st.push(i);     // Push index in stack not element
        }

        return nseIdx;
    }

    vector<int> findPSEE(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> pseeIdx(n, -1);      // In case of no PSEE, value will be -1

        for(int i = 0; i < n; i++) {
        // We need to find previous smaller or equal element, so if we get greater element on top of stack, remove it
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            pseeIdx[i] = st.empty() ? -1 : st.top();    // In case of no PSEE, value will be -1

            st.push(i);     // Push index in stack not element
        }

        return pseeIdx;
    }

    // Optimal Approach
    // T.C. = O(2n) for finding nse + O(2n) for finding psee + O(n) for finding contribution of each element as minimum in total = O(5n)
    // S.C. = O(2n) + O(2n) = O(4n)
    int sumSubarrayMins3(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        int mod = 1e9+7;    // 1e9 stands for 1 × 10^9

        // Array storing next smaller element indices of elements
        vector<int> nseIdx = findNSE(arr, n);       
        // Array storing previous smaller or equal element indices of elements
        vector<int> pseeIdx = findPSEE(arr, n);

        for(int i = 0; i < n; i++) {
            // Number of elements on left of arr[i] (including arr[i]) which are greater than arr[i] so that arr[i] will be minimum in the subarrays formed using them
            long long leftSide = i - pseeIdx[i];

            // Number of elements on right of arr[i] (including arr[i]) which are greater than or equal to arr[i] so that arr[i] will be minimum in the subarrays formed using them
            long long rightSide = nseIdx[i] - i;

            // Total number of subarrays formed where arr[i] is minimum
            long long totalSubArr = (leftSide * rightSide)*1LL;

            sum = (sum + (totalSubArr*arr[i])%mod)%mod;
        }

        return sum;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        // Brute Force Approach
        // return sumSubarrayMins1(arr);

        // Better Brute Force Approach
        // return sumSubarrayMins2(arr);

        // Optimal Approach
        return sumSubarrayMins3(arr);
    }
};