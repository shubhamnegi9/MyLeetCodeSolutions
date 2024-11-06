class Solution {
public:
    // Approach 1: Using Modified Bubble Sort
    bool canSortArray1(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n-1; i++) {
            bool swapped = false;
            for(int j = 0; j < n-i-1; j++) {
                
                if(nums[j] < nums[j+1]) {
                    // Already sorted order
                    // Continue to next element as no need to check for equal set bits
                    continue;   
                } else {
                    // Not in sorted order
                    int currSetBits = __builtin_popcount(nums[j]);
                    int nextSetBits = __builtin_popcount(nums[j+1]);
                    if(currSetBits == nextSetBits) {
                        // nums[j] and nums[j+1] can be swapped
                        swap(nums[j], nums[j+1]);
                        swapped = true;
                    } else {
                        // nums[j] and nums[j+1] cannot be swapped 
                        // So array can never be sorted
                        return false;
                    }
                }
            }
            
            if(swapped == false) {
                // Array is already sorted
                // No need to do further passes
                break;
            }
        }
        
        return true;
    }
    
    bool isSorted(vector<int>& nums) {
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i] > nums[i+1])
                return false;
        }
        return true;
    }
    
    // Approach 2: By creating set of segments in map and checking if segments are sorted
    // (Solved by own)
    bool canSortArray2(vector<int>& nums) {
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
    
    bool canSortArray(vector<int>& nums) {
        // Approach 1
        return canSortArray1(nums); 
        
        // Approach 2
        // return canSortArray2(nums);
        
        
    }
};