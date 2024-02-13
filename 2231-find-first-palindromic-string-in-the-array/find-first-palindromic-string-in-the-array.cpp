class Solution {
public:
    // Using string() method
    bool isPalindromic(string s) {
        // Creating a string using string() method
        // string() method takes begin and ending iterator of the word to be formed
        string reverseStr = string(s.rbegin(), s.rend());
        return s == reverseStr;
    }

    // Using equal() method
    bool isPalindromic2(string s) {
        int n = s.length();
        // equal() method takes first string's begin and ending iterator as first two arguments
        // and second string's begin iterator as third argument, and then compare the characters
        // between begin and end iterators in both the strings 
        return equal(s.begin(), s.begin()+n/2, s.rbegin());
    }

    string firstPalindrome(vector<string>& words) {
        for(string &s: words) {
            if(isPalindromic(s))
                return s;
        }
        return "";
    }
};