class Solution {
public:
    bool isNextElementPresent(vector<int>& nums, int ele) {
        for(int& num: nums) {
            if(ele == num)
                return true;
        }

        return false;
    }

    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    int longestConsecutive1(vector<int>& nums, int n) {
        int maxLen = 0;

        for(int i = 0; i < n; i++) {
            int currEle = nums[i];
            int len = 1;
            while(isNextElementPresent(nums, currEle+1)) {
                currEle++;
                len++;
            }
            maxLen = max(maxLen, len);
        }

        return maxLen;
    }

    bool isNextElementPresentBinary(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;

        while(low <= high) {
            int mid = low+(high-low)/2;
            if(nums[mid] == target)
                return true;
            else if(target > nums[mid]) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        return false;
    }

    // Better Brute Force Approach
    // T.C. = O(nlogn) for sorting + O(n*logn)
    // S.C. = O(1)
    int longestConsecutive2(vector<int>& nums, int n) {
        int maxLen = 0;

        // Sort the array to perform binary search
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            int currEle = nums[i];
            int len = 1;
            while(isNextElementPresentBinary(nums, currEle+1)) {
                currEle++;
                len++;
            }
            maxLen = max(maxLen, len);
        }

        return maxLen;
    }

    // Better Approach
    // T.C. = O(nlogn) for sorting + O(n)
    // S.C. = O(1)
    int longestConsecutive3(vector<int>& nums, int n) {
        // Sort the array to bring consecutive elements together
        sort(nums.begin(), nums.end());

        int maxLen = 0, len = 0, lastEle = INT_MIN;

        for(int i = 0; i < n; i++) {
            if(nums[i] == lastEle+1) {
                len++;
                lastEle = nums[i];
            }
            else if(nums[i] != lastEle) {
                len = 1;
                lastEle = nums[i];
            }
            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
    
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        // Brute Force Approach
        // return  longestConsecutive1(nums, n);

        // Better Brute Force Approach
        // return longestConsecutive2(nums, n);

        // Better Approach
        return longestConsecutive3(nums, n);
    }
};