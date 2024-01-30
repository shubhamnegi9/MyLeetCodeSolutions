class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string &tk: tokens) {
            if(tk != "/" && tk != "*" && tk != "+" && tk != "-") {
                st.push(stoi(tk));
            }
            else {
                int opr1 = st.top();
                st.pop();
                int opr2 = st.top();
                st.pop();
                int res;
                if(tk == "/")
                    res = (int) opr2/opr1; 
                else if(tk == "*")
                    res = opr2 * opr1;
                else if(tk == "-")
                    res = opr2 - opr1;
                else
                    res = opr2 + opr1;
                st.push(res);
            }
        }
        return st.top();
    }
};