class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high) {
        int left = low;
        int right = mid+1;
        vector<int> mergedArr;

        while(left <= mid && right <= high) {
            if(nums[left] < nums[right]) {
                mergedArr.push_back(nums[left]);
                left++;
            }
            else {
                mergedArr.push_back(nums[right]);
                right++;
            }
        }

        while(left <= mid) {
            mergedArr.push_back(nums[left]);
            left++;
        }

        while(right <= high) {
            mergedArr.push_back(nums[right]);
            right++;
        }

        for(int i = low; i <= high; i++) {
            nums[i] = mergedArr[i-low];
        }
    }

    int findReversePairCount(vector<int>& nums, int low, int mid, int high) {
        int count = 0;
        int right = mid+1;
        // Iterate for all element in first array
        for(int left = low; left <= mid; left++) {
            // Keep incrementing right pointer until reverse pair is found
            while(right <= high && nums[left] > 2* (long long) nums[right]) {
                right++;
            }
            // Elements from (mid+1) till right gives count of reverse pair in current iteration
            count += right - (mid+1);
        }

        return count;
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        int count = 0;
        // Base case
        if(low >= high) {
            return count;
        }

        int mid = low + (high - low)/2;

        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid+1, high);
        // Before merging left and right parts, count the reverse pairs
        count += findReversePairCount(nums, low, mid, high);
        merge(nums, low, mid, high);

        return count;
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};