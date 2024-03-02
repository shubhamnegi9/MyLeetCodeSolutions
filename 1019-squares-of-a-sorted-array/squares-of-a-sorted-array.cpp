class Solution {
public:
    // Brute Force
    // T.C. = O(n) + O(nlogn) for sorting
    // S.C. = O(1)
    void sortedSquaresBrute(vector<int> &nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
    }

    // Optimal Approach Using 2 Pointer
    // T.C. = O(n)
    // S.C. = O(n)
    vector<int> sortedSquaresOptimal(vector<int> &nums) {
        int n = nums.size();
        int i = 0, j = n-1;
        vector<int> res(n);
        int k = n-1;

        while(k >= 0) {
            int first = nums[i] * nums[i];
            int second = nums[j] * nums[j];

            // Putting greater of the two at end in res vector
            if(first < second) {
                res[k] = second;
                j--;
            }
            else {
                res[k] = first;
                i++;
            }
            k--;
        }

        return res;
    }

    vector<int> sortedSquares(vector<int>& nums) {
        // Brute Force
        // sortedSquaresBrute(nums);
        // return nums;
        
        // Optimal Approach
        return sortedSquaresOptimal(nums);
    }
};