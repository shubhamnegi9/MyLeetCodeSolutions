class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int i = 0, j = n-1;
        while(i < j && s[i] == s[j]) {
            // Move the pointers only if characters at both are equal
            char ch = s[i];
            // Move i to next character after prefix
            while(i < j && s[i] == ch) {
                i++;
            }
            // Move j to next character before suffix
            while(i <= j && s[j] == ch) {   // i <= j in case i reaches to j because of previous while loop
                j--;
            }
        }
        
        return j-i+1;
    }
};