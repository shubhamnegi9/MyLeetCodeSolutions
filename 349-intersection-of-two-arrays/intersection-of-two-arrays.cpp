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

    // Approach 4: using Binary search

    // Approach 5: using 2 pointers

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        // Approach 1: taking sets for nums1 and res
        // return intersectionUsingApproach1(nums1, nums2);

        // Approach 2 : taking sets for nums1 and nums2
        return intersectionUsingApproach2(nums1, nums2);
    }
};