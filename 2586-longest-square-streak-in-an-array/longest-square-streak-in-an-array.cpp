class Solution {
public:
    
    int longestSquareStreak1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        int maxStreak = 0;
        
        for(int num: nums) {
            int sqrtNum = sqrt(num);
            if(sqrtNum * sqrtNum == num && mp.find(sqrtNum) != mp.end()) {
                mp[num] = mp[sqrtNum]+1;
            } else {
                mp[num] = 1;
            }
            maxStreak = max(maxStreak, mp[num]);
        }
        
        return maxStreak >= 2 ? maxStreak : -1;
    }
    
    int longestSquareStreak(vector<int>& nums) {
        return longestSquareStreak1(nums);
    }
};