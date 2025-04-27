class Solution {
public:
    // Brute Force
    // T.C. = O(nlogn) + O(n)
    // S.C. = O(n)
    int removeDuplicates1(vector<int>& nums) {
        set<int> st;
        for(int& ele: nums) {
            st.insert(ele);
        }

        int i = 0;
        for(auto ele: st) {
            nums[i] = ele;
            i++;
        }

        return st.size();
    }

    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(1)
    int removeDuplicates2(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(int j = 1; j < n; j++) {
            if(nums[j] != nums[i]) {
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }

    int removeDuplicates(vector<int>& nums) {
        // Brute Force
        // return removeDuplicates1(nums);

        // Optimal Approach
        return removeDuplicates2(nums);
    }
};