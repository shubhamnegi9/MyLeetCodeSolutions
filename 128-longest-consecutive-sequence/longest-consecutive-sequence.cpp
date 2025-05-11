class Solution {
public:
    bool isFoundUsingLS(vector<int>& nums, int x) {
        for(int& ele: nums) {
            if(ele == x)
                return true;
        }
        return false;
    }

    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    int longestConsecutive1(vector<int>& nums, int n) {
        int maxCount = 0;
        for(int i = 0; i < n; i++) {
            int count = 1;
            int x = nums[i];
            while(isFoundUsingLS(nums, x+1)) {
                count++;
                x++;
            }       
            maxCount = max(maxCount, count);    
        }

        return maxCount;
    }

    bool isFoundUsingBS(vector<int>& nums, int x, int low, int high) {
        while(low <= high) {
            int mid = low + (high-low)/2;

            if(nums[mid] == x) {
                return true;
            } else if(nums[mid] > x) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return false;
    }

    // Better Brute Force Approach
    // T.C. = 2*O(nlogn)
    // S.C. = O(1)
    int longestConsecutive2(vector<int>& nums, int n) {
        int maxCount = 0;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            int count = 1;
            int x = nums[i];
            while(isFoundUsingBS(nums, x+1, 0, n-1)) {
                count++;
                x++;
            }       
            maxCount = max(maxCount, count);    
        }

        return maxCount;
    }

    // Better Approach
    // T.C. = O(nlogn) + O(n)
    // S.C. = O(1)
    int longestConsecutive3(vector<int>& nums, int n) {
        int maxCount = INT_MIN, count = 0, lastEle = INT_MAX;

        if(n == 0)
            return 0;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            if(nums[i]-1 == lastEle) {
                count++;
                lastEle = nums[i];
            } else if(nums[i] != lastEle) {
                count = 1;
                lastEle = nums[i];
            }
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
    
    // Optimal Approach
    // T.C. = O(n) + O(2n)
    // S.C. = O(n)
    int longestConsecutive4(vector<int>& nums, int n) {
        int maxCount = 1, count = 0;

        if(n == 0)
            return 0;

        unordered_set<int> st(nums.begin(), nums.end());

        // Iterate in set (Not in given array)
        for(auto ele: st) { 
            if(st.find(ele-1) == st.end()) {
                int currEle = ele;
                count = 1;
                while(st.find(currEle+1) != st.end()) {
                    count++;
                    currEle++;
                }
                maxCount = max(maxCount, count);
            }
        }

        return maxCount;
    }
    
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        // Brute Force Approach
        // return longestConsecutive1(nums, n);

        // Better Brute Force Approach
        // return longestConsecutive2(nums, n);

        // Better Approach
        // return longestConsecutive3(nums, n);

        // Optimal Approach
        return longestConsecutive4(nums, n);
    }
};