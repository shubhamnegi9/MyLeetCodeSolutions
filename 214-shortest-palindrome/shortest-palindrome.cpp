class Solution {
public:
    
    // Approach 1 (Using simple substring check for Prefix and Suffix)
    // Will give memory limit exceed due to substr() in C++
    string shortestPalindrome11(string s) {
        // Finding reverse of given string s
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        int n = s.length();
        for(int i = 0; i < n; i++) {
            // Checking if prefix in s == suffix in rev
            if(s.substr(0, n-i) == rev.substr(i, n)) {
                return rev.substr(0, i) + s;
            }
        }
        return rev + s;
    }
    
    // Approach 1 (Using simple substring check using memcmp() for Prefix and Suffix)
    string shortestPalindrome12(string s) {
        // Finding reverse of given string s
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        int n = s.length();
        for(int i = 0; i < n; i++) {
            // Checking if prefix in s == suffix in rev 
            if(memcmp(s.c_str(), rev.c_str()+i, n-i) == 0) {  // memcmp() will return 0 if both the substrings are same
                return rev.substr(0, i) + s;
            }
        }
        return rev + s;
    }
    
    string shortestPalindrome(string s) {
        // Approach 1 (Using simple substring check for Prefix and Suffix)
        // return shortestPalindrome11(s);
        
        // Approach 1 (Using simple substring check using memcmp() for Prefix and Suffix)
        return shortestPalindrome12(s);
    }
}; 