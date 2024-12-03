class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int i = 0;
        int idx = 0;
        if(spaces[idx] == 0) {
            result+=" ";
            idx++;
        }
        
        for(char ch: s) {
            i++;
            result+=ch;
            if(idx < spaces.size() && i == spaces[idx]) {
                result+=" ";
                idx++;
            }
        }
        return result;
    }
};