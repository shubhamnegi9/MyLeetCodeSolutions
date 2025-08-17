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
    
    vector<int> nextGreaterElements(vector<int>& nums) {
        // Brute Force Approach
        return nextGreaterElements1(nums);
    }
};