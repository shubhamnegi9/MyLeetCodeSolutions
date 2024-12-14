class Solution {
public:
    // Approach 1: Using ordered map
    // T.C. = O(2*n)*O(log(3)) = O(n)
    // S.C. = O(log(3)) = O(1)
    long long continuousSubarrays1(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        map<int, int> mp;
        
        int i = 0, j = 0;
        while(j < n) {
            
            mp[nums[j]]++;
            
            // Invalid subarray.Shrink the window
            // cout << "mp.rbegin()->first= " << mp.rbegin()->first << endl;
            // cout << "mp.begin()->first= " << mp.begin()->first << endl;
            while(mp.rbegin()->first - mp.begin()->first > 2) {    \
                // Reduce out of window element frequency in map
                mp[nums[i]]--;
                // Remove element from map if its frequency is 0
                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                                                               
                i++;
            }
            
            // Count of subarrays in valid window
            count += (j-i+1);
            j++;
        }
        
        return count;
    }
    
    // Approach 2: Using heap
    // T.C. = O(n*log(n))
    // S.C. = O(n)
    typedef pair<int, int> P;
    long long continuousSubarrays2(vector<int>& nums) {
        int n = nums.size();
        priority_queue<P> maxHeap;
        priority_queue<P, vector<P>, greater<P>> minHeap;
        long long count = 0;
        
        int i = 0, j = 0;
        while(j < n) {                  // O(n)
            P pair = {nums[j], j};
            maxHeap.push(pair);         // O(log(n))
            minHeap.push(pair);         // O(log(n))
            
            // Invalid subarray. Shrink the window
            while(maxHeap.top().first - minHeap.top().first > 2) {
                
                i++;
                
                // Remove out of window element from heaps
                while(!maxHeap.empty() && maxHeap.top().second < i) {
                    maxHeap.pop();
                }
                
                while(!minHeap.empty() && minHeap.top().second < i) {
                    minHeap.pop();
                }
            }
            
            count += (j-i+1);
            j++;
        }
        
        return count;
    }
    
    long long continuousSubarrays(vector<int>& nums) {
        // Approach 1: Using ordered map
        // return continuousSubarrays1(nums);
        
        // Approach 2: Using heap
        return continuousSubarrays2(nums);
    }
};