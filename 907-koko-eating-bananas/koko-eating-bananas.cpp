class Solution {
public:
    bool canEatAllBananas(vector<int> piles, int k, int h) {
        int actualHours = 0;
        for(int bananas: piles) {
            if(k >= bananas) {
                actualHours++;  // Can eat all bananas in 1 hour
            }
            else {
                actualHours += (bananas/k); // Takes (bananas/k) hours to eat bananas
                if(bananas % k > 0) {
                    actualHours++;      // Remaining bananas can be eaten in 1 hour
                }
            }
        }
        
        return actualHours <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;                                          // Minimum banannas which can be eaten in 1 hour
        int r = *max_element(piles.begin(), piles.end());   // Maximum banannas which can be eaten in 1 hour
        
        while(l < r) {
            int mid = l + (r-l)/2;
        
            if(canEatAllBananas(piles, mid, h)) {
                r = mid;    // Shifting search range to left to get smaller value of k
            } else {
                l = mid+1;  // Shifting search range to right to get larger value of k
            }
        }
        
        return l;
    }
};