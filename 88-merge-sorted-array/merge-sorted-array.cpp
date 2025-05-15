class Solution {
public:
    // Brute Force Approach
    // T.C. = 2*O(m+n)
    // S.C. = O(m+n) 
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        int i = 0, j = 0;
        
        while(i < m && j < n) {
            if(nums1[i] <= nums2[j]) {
                temp.push_back(nums1[i]);
                i++;
            } else {
                temp.push_back(nums2[j]);
                j++;
            }
        }

        while(i < m) {
            temp.push_back(nums1[i]);
            i++;
        }

        while(j < n) {
            temp.push_back(nums2[j]);
            j++;
        }

        for(int i = 0; i < m+n; i++) {
            nums1[i] = temp[i];
        }
    }

    // Optimal Approach 1
    // T.C. = O(min(m,n)) + O(mlogm) + O(nlogn)
    // S.C. = O(1) 
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = 0;

        while(i >= 0 && j < n && nums1[i] > nums2[j]) {
            swap(nums1[i], nums2[j]);
            i--;
            j++;
        }

        sort(nums1.begin(), nums1.begin()+m);
        sort(nums2.begin(), nums2.end());

        for(int i = m; i < m+n; i++) {
            nums1[i] = nums2[i-m];
        }
    }
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Brute Force Approach
        // merge1(nums1, m, nums2, n);

        // Optimal Approach 1
        merge2(nums1, m, nums2, n);
    }
};