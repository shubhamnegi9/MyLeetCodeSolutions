class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int minPrice = INT_MAX;
        int secondMinPrice = INT_MAX;
        for(auto ele: prices) {
            if(ele < minPrice) {
                secondMinPrice = minPrice;
                minPrice = ele;
            }
            else if(ele < secondMinPrice) {
                secondMinPrice = ele;
            }
        }
        int minCost = minPrice + secondMinPrice;
        if(money - minCost >= 0)
            return money - minCost;
        
        return money;
    }
};