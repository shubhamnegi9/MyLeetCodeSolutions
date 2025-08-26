class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n-k) * O(k) = O(n^2) if k == n
    // S.C. = O(n-k) size for maxList
    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxList;

        for(int i = 0; i <= n-k; i++) {
            int maxEle = nums[i];
            for(int j = i; j <= i+k-1; j++) {
                maxEle = max(maxEle, nums[j]);
            }
            maxList.push_back(maxEle);
        }

        return maxList;
    }   

    // Optimal Approach
    // T.C. = O(n) for traversing in array + O(n) for all push/pop operations in deque = O(2n)
    // S.C. = O(k) for deque + O(n-k) size for maxList
    vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxList;
        deque<int> dq;

        for(int i = 0; i < n; i++) {
            // Remove out of window elements from deque
            if(!dq.empty() && dq.front() <= i-k) {
                dq.pop_front();
            }

            // Maintaining monotonic decreasing deque
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);     // Push index not element

            if(i >= k-1) {
                maxList.push_back(nums[dq.front()]);      // nums[dq.front()] will give maximum of k size window
            }
        }

        return maxList;
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Brute Force Approach
        // return maxSlidingWindow1(nums, k);

        // Optimal Approach
        return maxSlidingWindow2(nums, k);
    }
};