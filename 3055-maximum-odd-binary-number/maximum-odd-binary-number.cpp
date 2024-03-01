class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        int countOf1 = count(s.begin(), s.end(), '1');
        int countOf0 = n-countOf1;
        string res;
        // Creating a new string using string(freq, ch)
        // Eg. if ch = 'a' and freq = 3, then temp = string(freq, ch) = "aaa"
        res += string(countOf1-1, '1');
        res += string(countOf0, '0');
        res += string(1, '1'); 
        return res;
    }
};