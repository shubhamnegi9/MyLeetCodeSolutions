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

    void swapIfGreater(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if(nums1[i] > nums2[j])
            swap(nums1[i], nums2[j]);
    }

    // Optimal Approach 2 (Using Gap Method)
    // T.C. = O(log(m+n)) * O(2n)
    // S.C. = O(1) 
    void merge3(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m+n;
        int gap = len/2 + len%2;

        while(gap > 0) {
            int left = 0, right = left+gap;

            while(right < len) {
                // left pointer is in first array and right pointer is in second array
                if(left < m && right >= m) {
                    swapIfGreater(nums1, nums2, left, right-m);
                } 
                // left pointer and right pointer are in second array
                else if(left >= m) {
                    swapIfGreater(nums2, nums2, left-m, right-m);
                }
                // left pointer and right pointer are in first array
                else {
                    swapIfGreater(nums1, nums1, left, right);
                }

                left++;
                right++;
            }

            if(gap == 1) {
                break;
            }

            gap = gap/2 + gap%2;
        }

        for(int i = m; i < m+n; i++) {
            nums1[i] = nums2[i-m];
        }
    }
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Brute Force Approach
        // merge1(nums1, m, nums2, n);

        // Optimal Approach 1
        // merge2(nums1, m, nums2, n);

        // Optimal Approach 2
        merge3(nums1, m, nums2, n);
    }
};