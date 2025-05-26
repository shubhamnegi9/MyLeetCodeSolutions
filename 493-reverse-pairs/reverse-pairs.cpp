class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    int reversePairs1(vector<int>& nums, int n) {
        int count = 0;
        for(int i = 0; i < n; i++)  {
            for(int j = i+1; j < n; j++) {
                if((long long) nums[i] > 2L*nums[j]) 
                    count++;
            }
        }

        return count;
    }

    void merge(vector<int>& nums, int low, int mid, int high) { // O(n)
        int left = low, right = mid+1;
        vector<int> temp;

        while(left <= mid && right <= high) {
            if(nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        while(right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        for(int i = low; i <= high; i++) {
            nums[i] = temp[i-low];
        }
    }

    int findReversePairs(vector<int>& nums, int low, int mid, int high) {   // O(n)
        int count = 0;
        int right = mid+1;

        for(int left = low; left <= mid; left++) {
            while(right <= high && (long long)nums[left] > 2L*nums[right]) {
                right++;
            }
            count += (right-(mid+1));
        }

        return count;
    }

    int mergeSort(vector<int>& nums, int low, int high) {   // O(logn)
        // base case
        if(low >= high)
            return 0;

        int count = 0; 
        int mid = low+(high-low)/2;
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid+1, high);
        count += findReversePairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return count;
    }

    // Optimal Approach
    // T.C. = O((n+n)*logn) = O(2n*logn)
    // S.C. = O(n) for temp vector
    int reversePairs2(vector<int>& nums, int n) {
        return mergeSort(nums, 0, n-1);
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        // Brute Force Approach
        // return reversePairs1(nums, n);

        // Optimal Approach
        return reversePairs2(nums, n);
    }
};