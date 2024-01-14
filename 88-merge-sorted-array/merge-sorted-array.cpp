class Solution {
public: 
    void swapIfGreater(vector<int>& nums1, int i, vector<int>& nums2, int j) {
        if(nums1[i] > nums2[j])
            swap(nums1[i], nums2[j]);
    }

    void mergeUsingGap(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Using gap method 
        int len = m+n;
        int gap = len/2 + len%2;

        if(m==0) {
            // Move all elements from num1 to num2
            for(int i=0; i < n; i++) {
                nums1[i] = nums2[i];
            }
        }
        else {
            while(gap > 0) {
                int left = 0, right = left + gap;

                while(right < len) {
                    // If left pointer is in first array and right pointer is in second array
                    if(left < m && right >= m) {
                        swapIfGreater(nums1, left, nums2, right-m);
                    }
                    // If both left and righ pointers are in second array
                    else if(left >= m) {
                        swapIfGreater(nums2, left-m, nums2, right-m);
                    }
                    // If both left and right pointers are in first array
                    else {
                        swapIfGreater(nums1, left, nums1, right);
                    }
                    left++, right++;
                }

                if(gap == 1)
                    break;
                
                gap = gap/2 + gap%2;
            }

            for(int i=0; i < n; i++) {
                nums1[m+i] = nums2[i];
            }
        }
    }

    void mergeOptimally(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0) {
            // Copying all values from nums2 to nums1
            for(int i = 0; i < n; i++) {
                nums1[i] = nums2[i];
            }
        }
        
        if(m != 0 && n != 0) {
            int left = m-1, right = 0;
            // Swapping elements in nums1 and nums2
            // if element in nums1 > element in nums2
            while(left >= 0 && right < n) {
                if(nums1[left] > nums2[right]) {
                    swap(nums1[left], nums2[right]);
                    left--;
                    right++;
                }
                else {
                    break;
                }
            }
            // Sorting elements in nums1
            sort(nums1.begin(), nums1.begin() + m);
            // Sorting elements in nums2
            sort(nums2.begin(), nums2.end());

            // Moving elements in nums2 to end of nums1
            for(int i = 0; i < n; i++) {
                nums1[m+i] = nums2[i]; 
            }
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Using optimal method
        // mergeOptimally(nums1, m, nums2, n);
        
        // Using gap method 
        mergeUsingGap(nums1, m, nums2, n);
    }
};