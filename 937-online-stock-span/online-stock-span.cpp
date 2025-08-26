class StockSpanner {
public:
    vector<int> arr;
    int count;
    StockSpanner() {
        arr = {};       // Empty vector
        count = 0;
    }
    
    int next(int price) {
        arr.push_back(price);
        count = 1;      // Make count = 1 on each day as we need to include current day always in stock span

        int n = arr.size();
        for(int i = n-2; i >= 0; i--) {     // Start iteration from day previous to current day
            if(arr[i] <= price) {
                count++;
            } else {
                break;      // break because we need to consider only consecutive days for which the stock price was less than or equal to the price of that day
            }
        }

        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */