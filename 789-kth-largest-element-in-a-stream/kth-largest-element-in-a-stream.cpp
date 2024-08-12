class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq; // Taking min-heap for finding Kth largest 
    int K;
    KthLargest(int k, vector<int>& nums) {
        for(int ele: nums) {
            pq.push(ele);
            // Whenever size of Min Heap becomes > K, we pop the smaller elements from top
            if(pq.size() > k) {
                pq.pop();
            }
        }
        K = k;
    }
    
    int add(int val) {
        pq.push(val);
        // Whenever size of Min Heap becomes > K, we pop the smaller elements from top
        if(pq.size() > K) {
            pq.pop();
        }
        // Element at the top of min heap will be kth largest element
        return pq.top();
    }

};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */