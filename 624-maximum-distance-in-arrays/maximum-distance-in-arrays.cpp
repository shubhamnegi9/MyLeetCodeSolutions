class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minEle = arrays[0].front();     // element at 0th index of first array
        int maxEle = arrays[0].back();      // element at last index of first array
        
        int n = arrays.size();
        int result = 0;
        
        for(int i = 1; i < n; i++) {
            int currMin = arrays[i].front();
            int currMax = arrays[i].back();
            
            result = max({result, abs(currMax-minEle), abs(currMin-maxEle)});
                
            minEle = min(minEle, currMin);
            maxEle = max(maxEle, currMax);
        }
        
        return result;
    }
};