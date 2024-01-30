class Solution {
public:
    // Basic Approach Using Stack
    int evalRPNUsingStack(vector<string>& tokens) {
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

    // Using fancy lambda on unordered map
    /*
        Syntax:
        unordered_map<key, function<return_type(input_type, input_type)>>
    */
    unordered_map<string, function<int(int, int)>> mpp =
        {
            {"+", [] (int a, int b) {return a+b;}},
            {"-", [] (int a, int b) {return a-b;}},
            {"*", [] (int a, int b) {return a*b;}},
            {"/", [] (int a, int b) {return a/b;}}
        };

    int evalRPNUsingStackAndLambda(vector<string>& tokens) {
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
                int res = mpp[tk](opr2, opr1);  // mpp[key](input, input)
                st.push(res);
            }
        }
        return st.top();
    }

    int evalRPN(vector<string>& tokens) {
       // return evalRPNUsingStack(tokens);

        return evalRPNUsingStackAndLambda(tokens);
    }
};