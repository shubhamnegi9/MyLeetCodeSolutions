class Solution {
public:
    
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

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return findMedianSortedArrays1(nums1, nums2);
    }
};