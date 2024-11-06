class Solution {
public:
    bool isSorted(vector<int>& nums) {
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i] > nums[i+1])
                return false;
        }
        return true;
    }
    
    bool canSortArray(vector<int>& nums) {
        
        if(isSorted(nums))
            return true;
        
        map<int, set<int>> mp;
        int prevSetBits = -1;
        int i = 0;
        for(int& num: nums) {
            int setBits = __builtin_popcount(num);
            if(setBits != prevSetBits) {
                i++;
            }
            mp[i].insert(num);
            prevSetBits = setBits;
        }
        
        auto prev = mp.begin();
        for(auto it = next(mp.begin(),1); it != mp.end(); it++) {
            set<int> currSet = it->second;
            set<int> prevSet = prev->second;
            int minCurrSet = *min_element(currSet.begin(), currSet.end());
            int maxPrevSet = *max_element(prevSet.begin(), prevSet.end());
            
            if(minCurrSet < maxPrevSet)
                return false;
             prev = it;
        }
        return true;
    }
};