class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;
        for(int& ele: nums) {
            if(ele == 1) { 
                count++;
                maxCount = max(maxCount, count);
            } else
                count = 0;
        }

        return maxCount;
    }
};