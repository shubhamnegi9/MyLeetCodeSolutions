class Solution {
public:
    // Brute Force approach with extra space
    // T.C. = O(m+n) for putting in mergedNums 
    // S.C = O(m+n) for mergedNums
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0) {
            nums1 = nums2;
        }
        
        if(m != 0 && n != 0) {
            vector<int> mergedNums;
            int p1 = 0, p2 = 0;
            while(p1 < m && p2 < n) {           // O(m+n)
                if(nums1[p1] < nums2[p2]) {
                    mergedNums.push_back(nums1[p1]);
                    p1++;
                } 
                else {
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
    }
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Brute Force approach with extra space
        merge1(nums1, m, nums2, n);
    }
};