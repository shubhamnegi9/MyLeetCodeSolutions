class Solution {
public:
    // Approach 1: Using sorting by custom comparator
    // T.C. = O(nlogn), S.C. = O(1)
    vector<int> lexicalOrder1(int n) {
        vector<int> result;
        
        for(int i = 1; i <= n; i++) {
            result.push_back(i);
        }
        
        auto cmp = [&](int &num1, int &num2) {
            string a = to_string(num1);
            string b = to_string(num2);
            return a < b;
        };
        
        sort(result.begin(), result.end(), cmp);
        return result;
    }
    
    
    // Approach 2: Using Recursion as DFS
    // T.C. = O(n), S.C. = O(1)
    void solve(int startNum, int n, vector<int> &result) {
        
        if(startNum > n) {
            return;
        }
        
        result.push_back(startNum);
        for(int append = 0; append <= 9; append++) {
            int newNum = startNum*10 + append;
            if(newNum > n) {
                return;
            }
            solve(newNum, n, result);
        }
    }
        
    vector<int> lexicalOrder2(int n) {
        vector<int> result;
        
        for(int startNum = 1; startNum <= 9; startNum++) {
            solve(startNum, n, result);
        }
        
        return result;
    }
    
    vector<int> lexicalOrder(int n) {
        // Approach 1: Using sorting by custom comparator
        // return lexicalOrder1(n);
        
        // Approach 2: Using Recursion as DFS
        return lexicalOrder2(n);
    }
};