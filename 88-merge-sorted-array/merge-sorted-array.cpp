class Solution {
public:
    
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> mergedNums;

        int p1 = 0, p2 = 0;

        while(p1 < m && p2 < n) {
            if(nums1[p1] <= nums2[p2]) {
                mergedNums.push_back(nums1[p1]);
                p1++;
            } else {
                mergedNums.push_back(nums2[p2]);
                p2++;
            }
        }

        while(p1 < m) {
            mergedNums.push_back(nums1[p1]);
            p1++;
        }
        while(p2 < n) {
            mergedNums.push_back(nums2[p2]);
            p2++;
        }

        nums1 = mergedNums;
    }

    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m > 0 && n > 0) {
            int p1 = m-1, p2 = 0;
            while(p1 >= 0 && p2 < n) {
                if(nums1[p1] > nums2[p2]) {
                    swap(nums1[p1], nums2[p2]);
                    p1--;
                    p2++;
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
        else if(n > 0) {
            nums1 = nums2;
        }
    }

    void swapIfGreater(vector<int>& nums1, int p1, vector<int>& nums2, int p2) {
        if(nums1[p1] > nums2[p2])
            swap(nums1[p1], nums2[p2]);
    }

    void merge3(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int total = (m+n);
        int gap = total/2 + total%2;

        while(gap > 0) {
            int left = 0;
            int right = left+gap;

            while(right < total) {
                if(left < m && right >= m) {
                    swapIfGreater(nums1, left, nums2, right-m);
                } 
                else if(left >= m) {
                    swapIfGreater(nums2, left-m, nums2, right-m);
                } 
                else {
                    swapIfGreater(nums1, left, nums1, right);
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
        // return merge1(nums1, m, nums2, n);

        // return merge2(nums1, m, nums2, n);

        return merge3(nums1, m, nums2, n);
    }
};