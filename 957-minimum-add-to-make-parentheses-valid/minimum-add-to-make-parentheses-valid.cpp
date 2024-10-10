class Solution {
public:
    // Approach 1: Using stack
    //T.C : O(n)
    //S.C : O(n)
    int minAddToMakeValid1(string s) {
        stack<int> stk;
        for(char ch: s) {
            if(ch == '(') {
                stk.push(ch);
            } else if(stk.size() > 0 && stk.top() == '(') {
                stk.pop();
            } else {
                stk.push(ch);
            }
        } 

        return stk.size();
    }
    
    // Approach 2: Without using stack
    //T.C : O(n)
    //S.C : O(1)
    int minAddToMakeValid2(string s) {
        int size = 0;   // Closing brackets required to make valid
        int open = 0;   // Opening brackets required to make valid
        for(char ch: s) {
            if(ch == '(') {
                size++;
            } else if(size > 0) {   // Current character is ')' and there are some '(' previously
                size--;
            } else {                // Current character is ')' and there are no '(' previously
                open++;
            }
        }
        
        return size+open;
    }
    
    int minAddToMakeValid(string s) {
        // Approach 1: Using stack
        // return minAddToMakeValid1(s);
        
        // Approach 2: Without using stack
        return minAddToMakeValid2(s);
     
    }
};