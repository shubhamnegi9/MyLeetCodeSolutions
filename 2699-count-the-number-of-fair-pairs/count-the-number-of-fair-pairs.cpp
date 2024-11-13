class Solution {
public:
    
    long long countFairPairs1(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<pair<long, long>> pairs;
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                int sum = nums[i] + nums[j];
                if(sum >= lower && sum <= upper) {
                    pairs.push_back({i, j});
                }
            }
        }
        
        return pairs.size();
    }
    
    long long countFairPairs2(vector<int>& nums, int lower, int upper) {
         int n = nums.size();

        sort(begin(nums), end(nums)); //nlogn

        long long result = 0;

        for(int i = 0; i < n; i++) { //O(n * logn)
             //o(n)
            int idx = lower_bound(begin(nums) + i + 1, end(nums), lower-nums[i]) - begin(nums); //Gives the firstc element NOT LESS than (lower - nums[i]) //log(n)
            int x   = idx - 1 - i;

            idx = upper_bound(begin(nums) + i + 1, end(nums), upper-nums[i]) - begin(nums); //Gives the firstc element GREATER than (upper - nums[i]) //log(n)

            int y = idx - 1 - i;

            result += (y-x);
        }

        return result;
    }
    
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // return countFairPairs1(nums, lower, upper); 
         return countFairPairs2(nums, lower, upper);
    }
};