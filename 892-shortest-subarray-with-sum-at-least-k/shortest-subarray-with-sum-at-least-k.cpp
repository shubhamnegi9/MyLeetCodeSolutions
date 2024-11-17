class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int j = 0;
        vector<long long> cumSum(n+1, 0);
        deque<int> deq;     // Monotonoic increasing deque
        int result = INT_MAX;
        
        while(j < n) {
            
            if(j == 0) {
                cumSum[j] = nums[j];
            } else {
                cumSum[j] = cumSum[j-1]+nums[j];
            }
            
            // If the cumulative sum from the start to j is already >= K, update result
            if(cumSum[j] >= k) {
                result = min(result, j+1);
            }
            
            // Shrinking the window
            // Remove indices from the deque until the subarray sum is >= K
            while(!deq.empty() && cumSum[j] - cumSum[deq.front()] >= k) {
                result = min(result, j - deq.front());
                deq.pop_front();
            }
            
            // Maintaining the monotonoic increasing deque (increasing order of cumulative sums)
            while(!deq.empty() && cumSum[j] <= cumSum[deq.back()]) {
                deq.pop_back();     // Remove indices that won't be useful
            }
            
            deq.push_back(j);
            j++;
        }
        
        return result == INT_MAX ? -1 : result;
    }
};