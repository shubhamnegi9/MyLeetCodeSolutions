class Solution {
public:
    int sumByDivisor(vector<int>& nums, int divisor) {
        int sum = 0;
        for(int& num: nums) {
            // Convert num and divisor to double otherwise it will lead to integer division 
            // and ceil will not work (We can also make any one of them as double)
            sum += ceil(double(num)/double(divisor));
        }
        return sum;
    }

    // Brute Force Approach
    // T.C. = O(maxEle * n)
    // S.C. = O(1)
    int smallestDivisor1(vector<int>& nums, int threshold) {
        int n = nums.size();
        // Additional check in case no divisor is present
        if(n > threshold)
            return -1;

        int max = *max_element(nums.begin(), nums.end());

        for(int i = 1; i <= max; i++) {
            if(sumByDivisor(nums, i) <= threshold) 
                return i;
        }

        return -1;
    }

    // Optimal Approach
    // T.C. = O(log(maxEle) * n)
    // S.C. = O(1)
    int smallestDivisor2(vector<int>& nums, int threshold) {
        int n = nums.size();
        // Additional check in case no divisor is present
        if(n > threshold)
            return -1;
        
        int low = 1, high = *max_element(nums.begin(), nums.end());

        while(low <= high) {
            int mid = low+(high-low)/2;

            if(sumByDivisor(nums, mid) <= threshold) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return low;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        // Brute Force Approach
        // return smallestDivisor1(nums, threshold);

        // Optimal Approach
        return smallestDivisor2(nums, threshold);
    }
};