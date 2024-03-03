class Solution {
public:
    int firstOccurence(vector<int>& arr, int n, int k) {
        int first = -1;
        int low = 0, high = n-1; 

        while(low <= high) {
            int mid = (low+high)/2;

            if(arr[mid] == k) {
                first = mid;
                high = mid-1;   // Move high to mid-1 to find first occurence
            }
            else if(arr[mid] < k) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }

        return first; 
    }

    int lastOccurence(vector<int>& arr, int n, int k) {
        int last = -1;
        int low = 0, high = n-1; 

        while(low <= high) {
            int mid = (low+high)/2;

            if(arr[mid] == k) {
                last = mid;
                low = mid+1;    // Move low to mid+1 to find last occurence
            }
            else if(arr[mid] < k) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }

        return last; 
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        int first = firstOccurence(nums, n, target);

        // In case if first occurence is not present, then last occurence will also not be present
        // So no need to find it and return {-1, -1}
        if(first == -1) {
            return {-1, -1};
        }

        int last = lastOccurence(nums, n, target);

        return {first, last};
    }
};