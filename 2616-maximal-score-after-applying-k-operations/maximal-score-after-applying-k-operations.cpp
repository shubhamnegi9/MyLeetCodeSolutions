class Solution {
public:
    
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
            nums[maxEleIndex] = ceil((double)nums[maxEleIndex]/3);
        }
        return result;
    }
    
    long long maxKelements2(vector<int>& nums, int k) {
        priority_queue<int> pq;
        
        for(int ele: nums) {
            pq.push(ele);
        }
        
        long long result = 0;
        while(k--) {
            int maxEle = pq.top();
            pq.pop();
            result += (long long) maxEle;
            pq.push(ceil((double)maxEle/3));
        }
        
        return result;
    }
    
    long long maxKelements(vector<int>& nums, int k) {
        
        // return maxKelements1(nums, k);
        
        return maxKelements2(nums, k);
    }
};