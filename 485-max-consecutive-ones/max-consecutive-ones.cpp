class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;
        for(int ele: nums) {
            if(ele == 1) {
                count++;
            }
             else {
                 maxCount = max(maxCount, count);
                 count = 0;
             }
        }
        maxCount = max(maxCount, count);
        
        return maxCount;
    }
};