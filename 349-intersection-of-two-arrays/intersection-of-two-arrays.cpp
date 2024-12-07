class Solution {
public:
    
    vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st2(nums2.begin(), nums2.end());
        unordered_set<int> st;
        
        for(int i = 0; i < nums1.size(); i++) {
            if(st2.find(nums1[i]) != st2.end()) {
                st.insert(nums1[i]);
            }
        }
        
        vector<int> result(st.begin(), st.end());
        return result;
    }
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        return intersection1(nums1, nums2);
        
    }
};