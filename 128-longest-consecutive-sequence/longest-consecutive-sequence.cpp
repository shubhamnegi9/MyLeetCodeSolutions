class Solution {
public:
    
    bool nextConsecutiveExist(vector<int>& nums, int x) {
        for(int& ele: nums) {
            if(ele == x)
                return true;
        }
        return false;
    }
    
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    int longestConsecutive1(vector<int>& nums) {
        int n = nums.size();
        
        // Corner case
        if(n==0)
            return 0;
        
        int maxLen = 1;
            
        for(int i = 0; i < n; i++) {
            int currEle = nums[i];
            int count = 1;
            
            while(nextConsecutiveExist(nums, currEle+1)) {
                count++;
                currEle++;
            }
            maxLen = max(maxLen, count);
        }
        
        return maxLen;
    }
    
    // Better Approach
    // T.C. = O(nlogn) + O(n)
    // S.C. = O(1)
    int longestConsecutive2(vector<int>& nums) {
        int n = nums.size();
        
        // Corner case
        if(n==0)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int lastConsecutiveEle = INT_MIN, count = 1, maxLen = 1;
        
        for(int& ele: nums) {
            if(ele == lastConsecutiveEle+1) {
                count++;
                lastConsecutiveEle = ele;
            } else if(ele == lastConsecutiveEle) {
                continue;
            } else {
                count = 1;
                lastConsecutiveEle = ele;
            }
            maxLen = max(maxLen, count);
        }
        
        return maxLen;
    }
    
    int longestConsecutive(vector<int>& nums) {
        // Brute Force Approach
        // return longestConsecutive1(nums);
        
        // Better Approach
        return longestConsecutive2(nums);
    }
};