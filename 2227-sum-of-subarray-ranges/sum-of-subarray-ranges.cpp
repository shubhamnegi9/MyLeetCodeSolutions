class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    long long subArrayRanges1(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;

        for(int i = 0; i < n; i++) {
            int smallest = nums[i];
            int largest = nums[i];
            for(int j = i+1; j < n; j++) {
                smallest = min(smallest, nums[j]);
                largest = max(largest, nums[j]);
                sum += (largest - smallest)*1LL;
            }
        }

        return sum;
    }
    
    long long subArrayRanges(vector<int>& nums) {
        // Brute Force Approach
        return subArrayRanges1(nums);
    }
};