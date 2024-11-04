class Solution {
public:
    // Using Recursion
    bool checkPalindrome(string s, int i, int j) {
        if(i > j) {
            return true;
        }
        
        if(s[i] != s[j])
            return false;
        
        return checkPalindrome(s, i+1, j-1);
    }
    
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        // cout << s << endl;
        
        string str;
        for(char& ch: s) {
            if(isalnum(ch))
                str+=ch;
        }
        // cout << str << endl;
        int n = str.length();
        
        // Using Recursion
        // return checkPalindrome(str, 0, n-1);
        
        // Using Loops
        int i = 0, j = n-1;
        while(i <= j) {
            if(str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};