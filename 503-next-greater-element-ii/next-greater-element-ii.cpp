class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(n)
    vector<int> nextGreaterElements1(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < i+n; j++) {
                int idx = j%n;      // Resp. index of j in nums array
                if(nums[idx] > nums[i]) {
                    nge[i] = nums[idx];
                    break;
                }
            }
        }

        return nge;
    }

    // Optimal Approach
    // T.C. = O(2n) + O(2n) = O(4n)
    // S.C. = O(2n) for stack + O(n) for NGE array 
    vector<int> nextGreaterElements2(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;

        for(int i = 2*n-1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums[i%n]) {   // Use (i%n) in place of i 
                st.pop();
            }

            if(i < n) {
                nge[i] = st.empty() ? -1 : st.top();    // NGE to only be stored for elements in range 0 to n-1
            }

            st.push(nums[i%n]);  // Use (i%n) in place of i 
        }

        return nge;
    }
    
    vector<int> nextGreaterElements(vector<int>& nums) {
        // Brute Force Approach
        // return nextGreaterElements1(nums);

        // Optimal Approach
        return nextGreaterElements2(nums);
    }
};