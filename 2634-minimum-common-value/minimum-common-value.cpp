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

    // Using Binary Search
    // T.C. = O(m*logn(n)) or O(n*logn(m))
    // S.C. = O(1)
    bool binarySearch(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(nums[mid] == target) {
                return true;
            }
            else if(nums[mid] < target) {
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }

        return false;
    }

    int getCommonUsingBinarySearch(vector<int>& nums1, vector<int>& nums2) {
        
        // Iterate in each element in nums1 and find it in nums2 using binary search
        for(int ele: nums1) {
            if(binarySearch(nums2, ele)) {
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
        // return getCommonUsingSet(nums1, nums2);

        // Using Binary Search
        // return getCommonUsingBinarySearch(nums1, nums2);

        // Using 2 pointer approach
        return getCommonUsing2Pointer(nums1, nums2);
    }
};