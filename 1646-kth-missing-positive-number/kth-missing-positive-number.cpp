class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n)
    // S.C. = O(1)
    int findKthPositive1(vector<int>& arr, int k) {
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            if(arr[i] <= k)
                k++;
            else
                break;
        }

        return k;
    }

    // Optimal Approach
    // T.C. = O(logn)
    // S.C. = O(1)
    int findKthPositive2(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n-1;

        while(low <= high) {
            int mid = low+(high-low)/2;
            int missing = arr[mid] - (mid+1);   // Number of missing numbers till mid

            if(missing < k) 
                low = mid+1;    // Eliminate left half of mid
            else
                high = mid-1;   // Elimintae right half of mid
        }

        return high+1+k;    // OR return (low+k);
    }

    int findKthPositive(vector<int>& arr, int k) {
        // Brute Force Approach
        // return findKthPositive1(arr, k);

        // Optimal Approach
        return findKthPositive2(arr, k);
    }
};