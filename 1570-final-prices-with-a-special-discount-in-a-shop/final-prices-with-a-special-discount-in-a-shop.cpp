class Solution {
public:
    bool isIncreasingSorted(vector<int>& prices) {
        for(int i = 0; i < prices.size()-1; i++) {
            if(prices[i] >= prices[i+1]) {
                return false;
            }
        }
        return true;
    }
    vector<int> finalPrices(vector<int>& prices) {
        if(isIncreasingSorted(prices)) {
            return prices;
        }
        
        int n = prices.size();
        for(int i = 0; i < n-1; i++) {
            int discount = -1;
            for(int j = i+1; j < n; j++) {
                if(prices[j] <= prices[i]) {
                    discount = prices[j];
                    break;
                }
            }
            if(discount != -1) 
               prices[i]-=discount; 
        }
        
        return prices;
    }
};