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

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Brute Force Approach
        // return findMedianSortedArrays1(nums1, nums2);

        // Better Approach
        return findMedianSortedArrays2(nums1, nums2);
    }
};