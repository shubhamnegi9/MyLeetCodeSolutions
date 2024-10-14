class Solution {
public:
    // Brute Force Approach
    // T.C. = O(k*n)
    // S.c. = O(1)
    long long maxKelements1(vector<int>& nums, int k) {
        int n = nums.size();
        int maxEle, maxEleIndex;
        long long result = 0;
        
        while(k--) {
            maxEle = nums[0];
            maxEleIndex = 0;
            for(int i = 1; i < n; i++) {
                if(nums[i] > maxEle) {
                    maxEle = nums[i];
                    maxEleIndex = i;
                }
            }
            result += (long long) maxEle;
            nums[maxEleIndex] = ceil(nums[maxEleIndex]/3.0);   // or ceil((float)nums[maxEleIndex]/3)
        }
        return result;
    }
    
    // Optimal Approach
    // T.C. = O(n) + O(k*logn) = O(n+k*logn)
    // S.c. = O(n)
    long long maxKelements2(vector<int>& nums, int k) {
        
        priority_queue<int> pq(nums.begin(), nums.end());   // Heapify
        
        long long result = 0;
        while(k--) {
            int maxEle = pq.top();
            pq.pop();
            result += (long long) maxEle;
            pq.push(ceil(maxEle/3.0));     // or ceil((float)maxEle/3)
        }
        
        return result;
    }
    
    long long maxKelements(vector<int>& nums, int k) {
        
        // return maxKelements1(nums, k);
        
        return maxKelements2(nums, k);
    }
};