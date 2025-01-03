class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    int reversePairs1(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(nums[i] > 2*nums[j])
                    count++;
            }
        }

        return count;
    }

    void merge(vector<int>& nums, int low, int mid, int high) {
        int left = low;
        int right = mid+1;
        vector<int> temp;
        
        while(left <= mid && right <= high) {
            if(nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
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

    int findReversePairCount(vector<int>& nums, int low, int mid, int high) {
        int count = 0;
        int right = mid+1;

        for(int left = low; left <= mid; left++) {
            // Cast nums[left] to long long and multiply by 2LL to ensure the multiplication happens in the long long domain, avoiding overflow.
            while(right <= high && (long long) nums[left] > 2LL * nums[right]) {
                right++;
            }
            count += (right-(mid+1));
        }

        return count;
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        int count = 0;

        // Base case
        if(low >= high)
            return count;
        
        int mid = low + (high-low)/2;
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid+1, high);
        // Before merging left and right parts, count the reverse pairs
        count += findReversePairCount(nums, low, mid, high);
        merge(nums, low, mid, high);
        return count;
    }

    // Optimal Approach
    // T.C. = O(2*n*logn)
    // S.C. = O(n)
    int reversePairs2(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
    
    int reversePairs(vector<int>& nums) {
        // Brute Force Approach
        // return reversePairs1(nums);

        // Optimal Approach
        return reversePairs2(nums);
    }
};