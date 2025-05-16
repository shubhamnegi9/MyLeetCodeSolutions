class Solution {
public:
    // T.C. = O(n)
    void merge(vector<int>& arr, int low, int mid, int high) {
        int left = low, right = mid+1;
        vector<int> temp;
        
        while(left <= mid && right <= high) {
            if(arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        while(left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i = low; i <= high; i++) {
            arr[i] = temp[i-low]; 
        }
    }
    
    // T.C. = O(n)
    int findReversePairCount(vector<int>& arr, int low, int mid, int high) {
        int count = 0;
        int right = mid+1;
        
        for(int left = low; left <= mid; left++) {
            // Keep moving right pointer until arr[j] form reverse pair with arr[i] 
            // Cast nums[left] to long long and multiply arr[right] by 2LL to ensure the multiplication happens in the long long domain, avoiding overflow.
            while(right <= high && (long long) arr[left] > 2LL*arr[right]) {
                right++;
            }
            
            // Increment the count of reverse pair by (right-(mid+1))
            count += (right-(mid+1));
        }
        
        return count;
    }
    
    int mergeSort(vector<int>& arr, int low, int high)  {
        int count = 0;
        // base case
        if(low >= high) 
            return 0;
            
        int mid = low + (high-low)/2;
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid+1, high);
        count += findReversePairCount(arr, low, mid, high);
        merge(arr, low, mid, high);
        
        return count;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};