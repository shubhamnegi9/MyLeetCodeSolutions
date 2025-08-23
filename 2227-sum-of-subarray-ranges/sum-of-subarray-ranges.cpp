class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    long long subArrayRanges1(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;

        for(int i = 0; i < n; i++) {
            int smallest = nums[i];
            int largest = nums[i];
            for(int j = i+1; j < n; j++) {
                smallest = min(smallest, nums[j]);
                largest = max(largest, nums[j]);
                sum += (largest - smallest)*1LL;
            }
        }

        return sum;
    }

    vector<int> findNSE(vector<int>& nums, int n) {
        vector<int> nseIdx(n, n);   // In case no NSE, then put n as index of NSE
        stack<int> st;
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            nseIdx[i] = st.empty() ? n : st.top();   // In case no NSE, then put n as index of NSE
            st.push(i);     // Push index not element itself
        }

        return nseIdx;
    }

    vector<int> findPSEE(vector<int>& nums, int n) {
        vector<int> pseeIdx(n, -1);   // In case no PSEE, then put -1 as index of PSEE
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            pseeIdx[i] = st.empty() ? -1 : st.top();   // In case no PSEE, then put -1 as index of PSEE
            st.push(i);     // Push index not element itself
        }

        return pseeIdx;
    }

    vector<int> findNGE(vector<int>& nums, int n) {
        vector<int> ngeIdx(n, n);   // In case no NGE, then put n as index of NGE
        stack<int> st;

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            ngeIdx[i] = st.empty() ? n : st.top();   // In case no NGE, then put n as index of NGE

            st.push(i); // Push index not element itself
        }

        return ngeIdx;
    }

    vector<int> findPGEE(vector<int>& nums, int n) {
        vector<int> pgeeIdx(n, -1);     // In case no PGEE, then put -1 as index of PGEE
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            pgeeIdx[i] = st.empty() ? -1 : st.top();    // In case no PGEE, then put -1 as index of PGEE

            st.push(i); // Push index not element itself
        }

        return pgeeIdx;
    }   

    long long sumSubarrayMins(vector<int>& nums, int n) {
        vector<int> nseIdx = findNSE(nums, n);      // List of indices of Next Smaller Elements 
        vector<int> pseeIdx = findPSEE(nums, n);    // List of indices of Previous Smaller or Equal Elements 
        long long sum = 0;

        for(int i = 0; i < n; i++) {
            int leftSide = i - pseeIdx[i];
            int rightSide = nseIdx[i] - i;

            long long totalSubarrays = (leftSide * rightSide)*1LL;

            sum += (totalSubarrays * nums[i]);
        }

        return sum;
    }

    long long sumSubarrayMaxs(vector<int>& nums, int n) {
        vector<int> ngeIdx = findNGE(nums, n);      // List of indices of Next Greater Elements 
        vector<int> pgeeIdx = findPGEE(nums, n);    // List of indices of Previous greater or Equal Elements 
        long long sum = 0;

        for(int i = 0; i < n; i++) {
            int leftSide = i - pgeeIdx[i];
            int rightSide = ngeIdx[i] - i;

            
            long long totalSubarrays = (leftSide * rightSide)*1LL;

            sum += (totalSubarrays * nums[i]);
        }

        return sum;
    }

    // Optimal Approach
    // T.C. = O(5n) + O(5n) = O(10n)
    // S.C. = O(5n) + O(5n) = O(10n)
    long long subArrayRanges2(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;

        long long sumOfSubarrayMins = sumSubarrayMins(nums, n);
        long long sumOfSubarrayMaxs = sumSubarrayMaxs(nums, n);

        return sumOfSubarrayMaxs - sumOfSubarrayMins;
    }
    
    long long subArrayRanges(vector<int>& nums) {
        // Brute Force Approach
        // return subArrayRanges1(nums);

        // Optimal Approach
        return subArrayRanges2(nums);
    }
};