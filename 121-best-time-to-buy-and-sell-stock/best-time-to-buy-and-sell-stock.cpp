class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < n; i++) {
            int sell = prices[i];
            int profit = sell-buy;
            maxProfit = max(maxProfit, profit);
            buy = min(buy, prices[i]);
        }

        return maxProfit;
    }
};