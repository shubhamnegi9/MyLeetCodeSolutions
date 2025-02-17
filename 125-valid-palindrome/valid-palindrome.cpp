class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(char ch: s) {
            if(isalnum(ch)) {
                temp+=ch;
            }
        }
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        cout << temp << endl;
        string reversed = temp;
        reverse(reversed.begin(), reversed.end());
        return reversed == temp;
    }
};