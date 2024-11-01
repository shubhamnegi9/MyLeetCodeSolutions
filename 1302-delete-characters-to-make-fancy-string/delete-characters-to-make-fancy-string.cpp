class Solution {
public:
    string makeFancyString(string s) {
        string result;
        result+=s[0];
        int count = 1;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == s[i-1]) {
                count++;
                if(count >= 3) {
                    continue;
                } else {
                    result+=s[i];
                }
            } else {
                result+=s[i];
                count = 1;
            }
        }
        
        return result;
    }
};