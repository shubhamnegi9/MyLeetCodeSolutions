class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0, m = nums1.size(), n = nums2.size();
        vector<int> result;

        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                i++;
            } else if(nums2[j] < nums1[i]) {
                j++;
            } else {
                if(result.size() == 0 || nums1[i] != result.back()) {
                    result.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }

        return result;
    }
};