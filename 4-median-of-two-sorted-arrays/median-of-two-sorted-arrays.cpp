class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n1+n2)
    // S.C. = O(n1+n2)
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> nums3;
        int i = 0, j = 0;

        while(i < n1 && j < n2) {
            if(nums1[i] < nums2[j]) {
                nums3.push_back(nums1[i]);
                i++;
            } else {
                nums3.push_back(nums2[j]);
                j++;
            }
        }

        while(i < n1) {
            nums3.push_back(nums1[i]);
            i++;
        }

        while(j < n2) {
            nums3.push_back(nums2[j]);
            j++;
        }

        int n = n1+n2;

        if(n % 2 == 1) {
            return (double) nums3[n/2];
        } 
        
        return (double)(nums3[n/2] + nums3[n/2-1])/2.0;
    }

    // Better Approach
    // T.C. = O(n1+n2)
    // S.C. = O(1)
    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1+n2;
        int ind1 = n/2-1, ind2 = n/2, el1 = -1, el2 = -1;
        int i = 0, j = 0;
        int cnt = 0;

        while(i < n1 && j < n2) {
            if(nums1[i] < nums2[j]) {
                if(cnt == ind1) {
                    el1 = nums1[i];
                } 
                if(cnt == ind2) {
                    el2 = nums1[i];
                }
                cnt++;
                i++;
            } else {
                if(cnt == ind1) {
                    el1 = nums2[j];
                } 
                if(cnt == ind2) {
                    el2 = nums2[j];
                }
                cnt++;
                j++;
            }
        }

        while(i < n1) {
            if(cnt == ind1) {
                el1 = nums1[i];
            } 
            if(cnt == ind2) {
                el2 = nums1[i];
            }
            cnt++;
            i++;
        }

        while(j < n2) {
            if(cnt == ind1) {
                el1 = nums2[j];
            } 
            if(cnt == ind2) {
                el2 = nums2[j];
            }
            cnt++;
            j++;
        }

        if(n % 2 == 1)
            return (double) el2;
        
        return (double)(el1+el2)/2.0;

    }
    
    // Optimal Approach
    // T.C. = O(log(min(n1, n2)))
    // S.C. = O(1)
    double findMedianSortedArrays3(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1+n2;

        // For making the binary search on smaller size array, we make first array passed as always smaller
        if(n1 > n2)
            return findMedianSortedArrays3(nums2, nums1);
        
        int left = (n1+n2+1)/2;     // Number of elements on left half of merged array
        int low = 0, high = n1;

        while(low <= high) {
            int mid1 = (low+high)>>1;   // Another way to write (low+high)/2
            int mid2 = left-mid1;
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

            if(mid1-1 >= 0)
                l1 = nums1[mid1-1];
            if(mid2-1 >= 0)
                l2 = nums2[mid2-1];
            if(mid1 < n1)
                r1 = nums1[mid1];
            if(mid2 < n2)
                r2 = nums2[mid2];
            
            if(l1 <= r2 && l2 <= r1) {
                // total number of elements from both arrays are odd
                if(n%2 == 1)
                    return max(l1, l2);     

                // total number of elements from both arrays are even
                return (double)(max(l1,l2) + min(r1, r2))/2.0;
            } else if(l1 > r2) {
                high = mid1-1;
            } else {
                low = mid1+1;
            }
        }

        return 0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Brute Force Approach
        // return findMedianSortedArrays1(nums1, nums2);

        // Better Approach
        // return findMedianSortedArrays2(nums1, nums2);

        // Optimal Approach
        return findMedianSortedArrays3(nums1, nums2);
    }
};