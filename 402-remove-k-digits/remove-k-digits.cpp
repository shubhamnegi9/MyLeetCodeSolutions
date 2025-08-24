class Solution {
public:
    // T.C. = O(3n) + O(k)
    // S.C. = O(n) fot stack + O(n) for res
    string removeKdigits(string s, int k) {
        int n = s.size();
        stack<char> st;     // Stack of char type

        for(int i = 0; i < n; i++) {
            while(!st.empty() && k > 0 && (s[i]-'0' < st.top()-'0')) {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }

        while(k > 0) {      // Edge case 3
            st.pop();
            k--;
        }

        if(st.empty())      // Egde case 1
            return "0";

        string res = "";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }

        while(res.size() > 0 && res.back() == '0') {    // Egde case 2
            res.pop_back();
        }

        reverse(res.begin(), res.end());

        if(res.empty())     // Egde case 1
            return "0";
        
        return res;
    }
};