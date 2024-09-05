class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int mSum = 0;
        for(int ele: rolls) {
            mSum+=ele;
        }
        int nSum = (mean*(m+n)) - mSum;
        
        // Out of range, return empty array
        if(nSum < n || nSum > 6*n) {
            return {};
        }
        
        int avg = nSum/n;
        int rem = nSum%n;
        vector<int> missing(n, 0);
        // Filling each entry of missing array with avg first, and then filling remainder value one by one in each entry
        for(int i = 0; i < n; i++) {
            missing[i] = avg;
            if(rem > 0) {
                missing[i]++;
                rem--;
            }
        }
        
        return missing;   
    }
};