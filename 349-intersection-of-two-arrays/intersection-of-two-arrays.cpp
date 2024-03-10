class Solution {
public:
    // Approach 1: taking sets for nums1 and result
    vector<int> intersectionUsingApproach1(vector<int>& nums1, vector<int>& nums2) {
        // Adding elements of nums1 in set to get unique elements
        unordered_set<int> s1(nums1.begin(), nums1.end());
        // Set for adding unqiue common elements
        unordered_set<int> s2;

        // Iterating in num2 and finding element in s1 and adding in s2 to get unique elements
        for(int ele: nums2) {  
            if(s1.find(ele) != s1.end())
                s2.insert(ele);
        }

        // Adding elements of set s2 in vector res
        vector<int> res(s2.begin(), s2.end());
        return res;
    }

    // Approach 2 : taking sets for nums1 and nums2
    vector<int> intersectionUsingApproach2(vector<int>& nums1, vector<int>& nums2) {
        // Adding elements of nums1 and nums2 in set to get unique elements in both
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        vector<int> res;

        // Iterating in s1 and finding element in s2
        for(int ele: s1) {  
            if(s2.find(ele) != s2.end())
                res.push_back(ele);
        }

        return res;
    }

    // Approach 3: taking set for nums1 only
    vector<int> intersectionUsingApproach3(vector<int>& nums1, vector<int>& nums2) {
        // Adding elements of nums1 in set to get unique elements
        unordered_set<int> s1(nums1.begin(), nums1.end());
        vector<int> res;

        // Iterating in nums2 and finding element in s1
        for(int ele: nums2) {  
            if(s1.find(ele) != s1.end()) {
                res.push_back(ele);
                // Remove the element from set s1 to get unique common element in both
                s1.erase(ele);
            }
        }

        return res;
    }

    // Approach 4: using Binary search
    bool binarySearch(vector<int> &nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high) {
            int mid = (low+high)/2;
            if(nums[mid] == target) {
                return true;
            }
            else if(target <= nums[mid]) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }

        return false;
    }

    vector<int> intersectionUsingBinarySearch(vector<int>& nums1, vector<int>& nums2) {
        // Sort elements of nums1 to apply Binary Search on it
        sort(nums1.begin(), nums1.end());
        // Set for adding unqiue common elements
        set<int> s;

        // Iterating in nums2 and finding element in nums1 using binary search
        for(int ele: nums2) {  
            if(binarySearch(nums1, ele)) {
                s.insert(ele);
            }
        }

        // Adding elements of set s in vector res
        vector<int> res(s.begin(), s.end());
        return res;
    }

    // Approach 5: using 2 pointers

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        // Approach 1: taking sets for nums1 and res
        // return intersectionUsingApproach1(nums1, nums2);

        // Approach 2 : taking sets for nums1 and nums2
        // return intersectionUsingApproach2(nums1, nums2);

        // Approach 3: taking set for nums1 only
        // return intersectionUsingApproach3(nums1, nums2);

        // Approach 4: using Binary search
        return intersectionUsingBinarySearch(nums1, nums2);
    }
};