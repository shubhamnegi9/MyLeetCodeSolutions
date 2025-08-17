class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n2) + O(n2^2) + O(n1)
    // S.C. = O(n2) for map + O(n1) for ans
    vector<int> nextGreaterElement1(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int, int> mpp;    // For mapping nums2 elements with their NGE

        for(int i = 0; i < n2; i++) {
            mpp[nums2[i]] = -1;     // Initialize all values of map with -1
        }

        for(int i = 0; i < n2-1; i++) {
            for(int j = i+1; j < n2; j++) {
                if(nums2[j] > nums2[i]) {
                    mpp[nums2[i]] = nums2[j];
                    break;
                }
            }
        }

        vector<int> ans;
        for(int i = 0; i < n1; i++) {
            ans.push_back(mpp[nums1[i]]);
        }

        return ans;
    }

    // Optimal Approach
    // T.C. = O(2*n2) + O(n1)
    // S.C. = O(n2) for map + O(n2) for stack + O(n1) for ans 
    vector<int> nextGreaterElement2(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int, int> mpp;    // For mapping nums2 elements with their NGE
        stack<int> st;

        for(int i = n2-1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if(st.empty()) {
                mpp[nums2[i]] = -1;
            } else {
                mpp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        vector<int> ans;
        for(int i = 0; i < n1; i++) {
            ans.push_back(mpp[nums1[i]]);
        }

        return ans;
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Brute Force Approach
        // return nextGreaterElement1(nums1, nums2);

        // Optimal Approach
        return nextGreaterElement2(nums1, nums2);
    }
};