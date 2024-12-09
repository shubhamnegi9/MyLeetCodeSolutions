class Solution {
public:
    
    // T.C. = O(n)
    // S.C. = O(1)
    int maxProfit1(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int minPrice = prices[0];
        
        for(int i = 1; i < n; i++) {
            int profit = prices[i] - minPrice;
            maxProfit = max(maxProfit, profit);
            minPrice = min(minPrice, prices[i]);
        }
        
        return maxProfit;
    }
    
    int maxProfit(vector<int>& prices) {
        
        return maxProfit1(prices);
    }
};