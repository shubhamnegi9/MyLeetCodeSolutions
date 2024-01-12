class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
    bool halvesAreAlike(string s) {
        int n = s.length();
        int p1 = 0, p2 = n-1;
        int vowelCount = 0;
        while(p1 < p2) {
            if(isVowel(s[p1]))
                vowelCount++;
            if(isVowel(s[p2]))
                vowelCount--;
            p1++;
            p2--;
        }
        return vowelCount==0;
    }
};