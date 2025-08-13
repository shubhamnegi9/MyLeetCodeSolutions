class Solution {
public:
    // T.C. = O(n)
    // S.C. = O(n) for stack
    bool isValid(string s) {
        stack<char> st;

        for(char ch: s) {
            // Opening bracket
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {
            // Closing bracket
                if(st.empty()) {   // Either no opening brackets or opening brackets are less than closing brackets
                    return false;  
                } else {
                    char top = st.top();
                    st.pop();

                    if((top == '(' && ch == ')') || 
                        (top == '{' && ch == '}') ||
                        (top ==  '[' && ch == ']')) {
                            continue;       // continue to iterate. Don't return true from here! 
                    } else {
                        return false;       // Brackets did not match
                    }
                }
            }
        }

        return st.empty();      // If stack is empty return true else return false
    }
}; 