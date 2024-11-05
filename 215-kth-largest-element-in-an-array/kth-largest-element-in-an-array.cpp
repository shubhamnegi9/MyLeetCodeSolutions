class Solution {
public:
    int findKthLargest1(vector<int>& nums, int k) {
        // Max heap
        priority_queue<int> pq(nums.begin(), nums.end());
        
        while(k-1) {
            pq.pop();
            k--;
        }
        
        return pq.top();
    }
    
    int findKthLargest2(vector<int>& nums, int k) {
        // Min Heap
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int num: nums) {
            pq.push(num);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        return pq.top();
    }
    int findKthLargest(vector<int>& nums, int k) {
        // Using Max heap
        // return findKthLargest1(nums, k);
        
        // Using Min heap
        return findKthLargest2(nums, k);
    }
};