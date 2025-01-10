class Solution {
public:
    bool nextExists(vector<int>& nums, int num) {
        for(int ele: nums) {
            if(ele == num)
                return true;
        }
        return false;
    }
    // Brute Force Approach 
    // T.C. = O(n^2)
    // S.C. = O(1)
    int longestConsecutive1(vector<int>& nums) {
        int n = nums.size();
        int maxCount = 0;

        for(int i = 0; i < n; i++) {
            int curr = nums[i];
            int count = 1;
            while(nextExists(nums, curr+1)) {
                curr++;
                count++;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }

    bool nextExistsBinary(vector<int>& nums, int low, int high, int num) {
        while(low <= high) {
            int mid = low+(high-low)/2;
            if(nums[mid] == num) {
                return true;
            } else if(num < nums[mid]) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return false;
    }

    // Better Brute Force Approach 
    // T.C. = O(n*logn) + O(n*logn)
    // S.C. = O(1)
    int longestConsecutive2(vector<int>& nums) {
        int n = nums.size();
        int maxCount = 0;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            int curr = nums[i];
            int count = 1;
            while(nextExistsBinary(nums, 0, n-1, curr+1)) {
                curr++;
                count++;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }

    // Better Approach
    // T.C. = O(n*logn) + O(n)
    // S.C. = O(1)
    int longestConsecutive3(vector<int>& nums) {
        int n = nums.size();

        if(n==0)
            return 0;

        sort(nums.begin(), nums.end());

        int count = 0;
        int maxCount = 1;
        int lastSmaller = INT_MIN;

        for(int i = 0; i < n; i++) {
            if(nums[i]-1 == lastSmaller) {
                count++;
                lastSmaller = nums[i];
            }
            else if(nums[i] == lastSmaller) {
                continue;
            }
            else {
                count = 1;
                lastSmaller = nums[i];
            }
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }

    // Optimal Approach
    // T.C. = O(n) + O(2n) = O(3n)
    // S.C. = O(n)
    int longestConsecutive4(vector<int>& nums) {
        int n = nums.size();

        if(n==0)
            return 0;

        unordered_set<int> st(nums.begin(), nums.end());
        int maxCount = 1;

        for(int i = 0; i < n; i++) {
            int currEle = nums[i];
            if(st.find(currEle-1) == st.end()) {
                int count = 1;
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
        /// Brute Force Approach 
        // return longestConsecutive1(nums);

        // Better Brute Force Approach 
        // return longestConsecutive2(nums);

        // Better Approach
        return longestConsecutive3(nums);

        // Optimal Approach
        return longestConsecutive4(nums);
    }
};