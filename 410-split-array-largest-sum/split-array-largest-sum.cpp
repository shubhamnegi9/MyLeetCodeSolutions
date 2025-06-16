class Solution {
public:

    int countSubarrays(vector<int>& arr, int totalSum, int n) {
        int count = 1, sum = 0;

        for(int i = 0; i < n; i++) {
            if(sum + arr[i] <= totalSum) {
                sum += arr[i];
            } else {
                count++;
                sum = arr[i];
            }
        }

        return count;
    }

    // Brute Force Approach
    // T.C. = O(sum-max+1) * O(n)
    // S.C. = O(1)
    int splitArray1(vector<int>& nums, int k) {
        int n = nums.size();

        // Impossible case
        if(k > n)
            return -1;

        int maxEle = *max_element(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);

        for(int i = maxEle; i <= sum; i++) {
            if(countSubarrays(nums, i, n) == k)
                return i;
        }

        return -1;
    }

    // Optimal Approach
    // T.C. = O(log(sum-max+1)) * O(n)
    // S.C. = O(1)
    int splitArray2(vector<int>& nums, int k) {
        int n = nums.size();

        // Impossible case
        if(k > n)
            return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high) {
            int mid = low+(high-low)/2;

            if(countSubarrays(nums, mid, n) > k) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        return low;
    }
    
    int splitArray(vector<int>& nums, int k) {
        // Brute Force Approach
        // return splitArray1(nums, k);

        // Optimal Approach
        return splitArray2(nums, k);
    }
};