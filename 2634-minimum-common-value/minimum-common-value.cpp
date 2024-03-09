class Solution {
public:

    // Using set
    // T.C. = O(m) for adding in set + O(n) for finding in set
    //      = O(m+n)
    // S.C. = O(m) or O(n) 
    int getCommonUsingSet(vector<int>& nums1, vector<int>& nums2) {
        
        // Taking unordered set and inserting all values of nums1 in set
        unordered_set<int> s(nums1.begin(), nums1.end());

        // Iterate in nums2 and check which element is present in set and return it
        for(int ele: nums2) {
            if(s.find(ele) != s.end()) {
                return ele;
            }
        }

        return -1;
    }

    // Using 2 pointer approach
    // T.C. = O(m+n), S.C. = O(1)
    int getCommonUsing2Pointer(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0, p2 = 0;
        int m = nums1.size(), n = nums2.size();

        while(p1 < m && p2 < n) {
            if(nums1[p1] == nums2[p2]) {
                return nums1[p1];
            }
            else if(nums1[p1] < nums2[p2]) {
                p1++;
            }
            else {
                p2++;
            }
        }

        return -1;
    }

    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        // Using set
        return getCommonUsingSet(nums1, nums2);

        // Using 2 pointer approach
        // return getCommonUsing2Pointer(nums1, nums2);
    }
};