class StockSpanner {
public:
    stack<pair<int, int>> st;      
    int ind;
    StockSpanner() {
        st.empty();
        ind = -1;
    }
    
    int next(int price) {
        ind++;

        while(!st.empty() && st.top().first <= price) {     // st.top().first will give price value
            st.pop();
        }
        // After popping all less than or equal elements from stack, PGE will be at top of stack
        int ans = ind - (st.empty() ? -1 : st.top().second);    // st.top().second will give day index
        
        st.push({price, ind});  // Push current element after calculating ans
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */