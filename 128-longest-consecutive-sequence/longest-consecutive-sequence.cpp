class Solution {
public:
    
    bool findNextConsecutive(vector<int>& nums, int ele) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == ele)
                return true;
        }    
        return false;
    }
    
    int longestConsecutive1(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        for(int i = 0; i < n; i++) {
            int currEle = nums[i];
            int count = 1;
            while(findNextConsecutive(nums, currEle+1)) {
                count++;
                currEle++;
            }
            maxLen = max(maxLen, count);
        }
        
        return maxLen;
    }
    
    int longestConsecutive2(vector<int>& nums) {
        int n = nums.size();
        
        if(n==0)
            return 0;
        
        sort(nums.begin(), nums.end());
        int count = 1;
        int maxLen = 0;
        int lastConsecutive = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(nums[i] == lastConsecutive+1) {
                count++;
                lastConsecutive = nums[i];
            } else if(nums[i] == lastConsecutive) {
                continue;
            } else {
                count = 1;
                lastConsecutive = nums[i];
            }
            maxLen = max(maxLen, count);
        }
        return maxLen;
    }
    
    int longestConsecutive(vector<int>& nums) {
        // return longestConsecutive1(nums);
        
        return longestConsecutive2(nums);
    }
};