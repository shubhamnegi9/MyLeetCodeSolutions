class Solution {
public:
    
    // Approach 1: Brute Force using sorting
    int smallestDistancePair1(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> distance;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int diff = abs(nums[i] - nums[j]);
                distance.push_back(diff);
            }
        }
        sort(distance.begin(), distance.end());
        return distance[k-1];
    }
    
    // Approach 2: Better Approach using Heaps
    int smallestDistancePair2(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq; // Taking Max Heap
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int diff = abs(nums[i] - nums[j]);
                pq.push(diff);
                // If size of heap > k, then pop from heap
                if(pq.size() > k) {
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
    
    // Approach 3: Better Approach by storing count of distances
    int smallestDistancePair3(vector<int>& nums, int k) {
        
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        int size = mx-mn;
        vector<int> v(size+1, 0);
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int diff = abs(nums[i]-nums[j]);
                // Storing count of distances in vector
                v[diff]++;
            }
        }
        
        for(int d = 0; d < v.size(); d++) {
            k -= v[d];
            if(k <= 0) {
                return d;
            }
        }
        
        return -1;
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        
        // Approach 1: Brute Force using sorting
        // return smallestDistancePair1(nums, k);
        
        // Approach 2: Better Approach using Heaps
        // return smallestDistancePair2(nums, k);
        
        // Approach 3: Better Approach by storing count of distances
        return smallestDistancePair3(nums, k);
    }
};