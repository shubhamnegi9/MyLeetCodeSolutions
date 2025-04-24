class Solution {
public:
    bool isPalindrome(string s) {
        string str;

        // filtering out non-alphanumeric characters
        for(char ch: s) {
            if(isalnum(ch)) {
                str+=ch;
            }
        }

        int i = 0;
        int n = str.length();

        if(n <= 1)
            return true;

        // Converting to lower case
        transform(str.begin(), str.end(), str.begin(), ::tolower);

        while(i < n/2) {
            if(str[i] != str[n-i-1])
                return false;
            i++;
        }
        return true;
    }
};