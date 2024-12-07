class Solution {
public:
    
    vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st2(nums2.begin(), nums2.end());
        unordered_set<int> st;
        
        for(int i = 0; i < nums1.size(); i++) {
            if(st2.find(nums1[i]) != st2.end()) {
                st.insert(nums1[i]);
            }
        }
        
        vector<int> result(st.begin(), st.end());
        return result;
    }
    
    vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2(nums2.begin(), nums2.end());
        vector<int> result;
        
        for(int ele: st1) {
            if(st2.find(ele) != st2.end()) {
                result.push_back(ele);
            }
        }
        return result;
    }
    
    vector<int> intersection3(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st2(nums2.begin(), nums2.end());
        vector<int> result;
        
        for(int ele: nums1) {
            if(st2.find(ele) != st2.end()) {
                result.push_back(ele);
                st2.erase(ele);
            }
        } 
        
        return result;
    }
    
    bool binarySearch(vector<int> nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target) {
                return true;
            }
            else if(target < nums[mid]) {
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        
        return false;
    }
    
    vector<int> intersection4(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        unordered_set<int> st;
        
        for(int ele: nums2) {
            if(binarySearch(nums1, ele)) {
                st.insert(ele);
            }
        }
        
        vector<int> result(st.begin(), st.end());
        return result;
    }
    
    vector<int> intersection5(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int m = nums1.size(), n = nums2.size();
        vector<int> result;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        while(i < m && j < n) {
            if(nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                
                while(i < m-1 && nums1[i] == nums1[i+1]) {
                    i++;
                }

                while(j < n-1 && nums2[j] == nums2[j+1]) {
                    j++;
                }
                
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }
        
        return result;
    }
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // return intersection1(nums1, nums2);
        
        // return intersection2(nums1, nums2);
        
        // return intersection3(nums1, nums2);
        
        // return intersection4(nums1, nums2);
        
        return intersection5(nums1, nums2);
    }
};