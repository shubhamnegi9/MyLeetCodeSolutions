class Solution {
public:
    int minAddToMakeValid(string s) {
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
};