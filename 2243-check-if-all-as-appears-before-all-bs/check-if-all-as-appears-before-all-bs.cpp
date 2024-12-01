class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        int i = 0;
        while(i < n) {
            if(s[i] == 'a')
                i++;
            else
                break;
        }
        
        for(int j = i; j < n; j++) {
            if(s[j] == 'a')
                return false;
        }
        
        return true;
    }
};