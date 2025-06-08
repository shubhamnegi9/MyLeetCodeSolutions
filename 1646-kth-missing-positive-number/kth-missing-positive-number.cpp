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

    int findKthPositive(vector<int>& arr, int k) {
        // Brute Force Approach
        return findKthPositive1(arr, k);
    }
};