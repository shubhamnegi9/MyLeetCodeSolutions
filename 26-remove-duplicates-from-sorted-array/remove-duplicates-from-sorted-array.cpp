class Solution {
public:
    // T.C. = O(n)
    // S.C. = O(n) + O(n)
    int removeDuplicates1(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        vector<int> temp(st.begin(), st.end());

        int n = temp.size();       
        for(int i = 0; i < n; i++) {
            nums[i] = temp[i];
        }
        return n;
    }
    
    int removeDuplicates(vector<int>& nums) {
        return removeDuplicates1(nums);
    }
};