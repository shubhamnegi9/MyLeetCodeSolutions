class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        /*
            Creating Array of Map where each map entry is <key, value> pair
            key: common difference of the AP which is ending with the element 'e' 
                 which is present at same index in given array 'nums'
            value: count of the APs which are ending with the element 'e' 
                 which is present at same index in given array 'nums'
        */
        unordered_map<long, int> mpp[n];
        int result = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                // Finding common difference of AP from nums[j] to nums[i]
                long commonDiff = (long) nums[j] - nums[i];

                /* 
                    Checking if we get any such AP before which was ending
                    with the same element as nums[j].
                    If we get such AP then we update the current AP count as
                    (the count of those AP's + 1) to existing AP count. 
                    Otherwise we update count as 1.
                */
                auto it = mpp[j].find(commonDiff);

                int count = (it == mpp[j].end()) ? 0 : it->second;

                mpp[i][commonDiff] += count + 1;
                /*
                    Updating resulting arithmetic subsequences count 
                    as count
                */
                result += count;
            }
        }

        return result;
    }
};