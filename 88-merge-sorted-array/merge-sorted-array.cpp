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
            // Copy mergedNums to nums1
            nums1 = mergedNums;
        }
    }
    
    // Optimal Approach using 2 pointer witout extra space
    // T.C. = O(min(m, n)) for placing number in correct arrays + O(mlogm) for sorting nums1 + o(nlogn) for sorting num2 + O(n) for copy nums2 to end of nums1
    // S.C. = O(1)
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0) {
            nums1 = nums2;
        }
        
        if(m != 0 && n != 0) {
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
            
            sort(nums1.begin(), nums1.begin()+m);   // Don't sort till nums1.end() because there are 0s at end 
            sort(nums2.begin(), nums2.end());
            
            // Copy nums2 to end of nums1
            for(int i = m; i < m+n; i++) {
                nums1[i] = nums2[i-m];
            }
        }
    }
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Brute Force approach with extra space
        // merge1(nums1, m, nums2, n);
        
        // Optimal Approach using 2 pointer witout extra space
        merge2(nums1, m, nums2, n);
    }
};