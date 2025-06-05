class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        // Single elememt as peak
        if(n == 1)
            return 0;
        // First element is peak
        if(arr[0] > arr[1])
            return 0;
        // Last element is peak
        if(arr[n-1] > arr[n-2])
            return n-1;
        
        int low = 1, high = n-2;

        while(low <= high) {
            int mid = low+(high-low)/2;

            // Element at mid is peak
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
                return mid;
            // mid is at increasing curve
            else if(arr[mid] > arr[mid-1])
                low = mid+1;
            // mid is at decreasing curve
            else if(arr[mid] > arr[mid+1])
                high = mid-1;
        }

        return -1;
    }
};