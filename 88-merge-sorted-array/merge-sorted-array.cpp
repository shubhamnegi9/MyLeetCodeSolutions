class Solution {
public:
    // Brute Force Approach
    // T.C. = O(m+n) + O(m+n)
    // S.C. = O(m+n)
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> merged;
        int i = 0, j = 0;

        while(i < m && j < n) {
            if(nums1[i] <= nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }

        while(i < m) {
            merged.push_back(nums1[i]);
            i++;
        }

        while(j < n) {
            merged.push_back(nums2[j]);
            j++;
        }

        for(int i = 0; i < m+n; i++) {
            nums1[i] = merged[i];
        }
    }

    // Optimal Approach
    // T.C. = O(m+n) + O(n)
    // S.C. = O(1)
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = 0;

        while(i >= 0 && j < n) {
            if(nums1[i] > nums2[j]) {
                swap(nums1[i], nums2[j]);
                i--;
                j++;
            } else {
                break;
            }
        }

        sort(nums1.begin(), nums1.begin()+m);
        sort(nums2.begin(), nums2.end());

        for(int i = m; i < m+n; i++) {
            nums1[i] = nums2[i-m];
        }
    }
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Brute Force Approach 
        // return merge1(nums1, m, nums2, n);

        // Optimal Approach
        return merge2(nums1, m, nums2, n);
    }
};