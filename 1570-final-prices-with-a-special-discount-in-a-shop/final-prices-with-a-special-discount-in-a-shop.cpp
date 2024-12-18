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
    
    // BruteForce Approach
    // T.C. = O(n^2)
    // S.C. = O(1) (O(n) if separate result vector is used)
    vector<int> finalPrices1(vector<int>& prices) {
        if(isIncreasingSorted(prices)) {
            return prices;
        }
        
        int n = prices.size();
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                if(prices[j] <= prices[i]) {
                    prices[i]-=prices[j]; 
                    break;
                }
            }
        }
        
        return prices;
    }
    
    // Optimal Approach using Monotonic Stack
    vector<int> finalPrices2(vector<int>& prices) {
        vector<int> result(prices); // Copy prices vector into result vector so that input is not modified
        int n = prices.size();
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            
            while(!st.empty() && prices[i] <= result[st.top()]) {
                result[st.top()]-=prices[i];
                st.pop();
            }
            
            st.push(i);
        }
        
        return result;
    }
    
    vector<int> finalPrices(vector<int>& prices) {
        
        // BruteForce Approach
        // return finalPrices1(prices);
        
        // Optimal Approach using Monotonic Stack
        return finalPrices2(prices);
    }
};