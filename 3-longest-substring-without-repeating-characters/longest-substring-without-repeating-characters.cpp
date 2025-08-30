class Solution {
public:
    // Brute Force Approach
    int lengthOfLongestSubstring1(string s) {
        int n = s.length();
        int maxLen = 0;
        for(int i = 0; i < n; i++) {
            int hash[256] = {0};    // Reset/define the hash array whenever we have new starting point of substring
            for(int j = i; j < n; j++) {
                if(hash[s[j]] == 1)     // Repeating character
                    break;
                
                int len = j-i+1;
                maxLen = max(maxLen, len);
                hash[s[j]] = 1;
            }
        }

        return maxLen;
    }
    
    int lengthOfLongestSubstring(string s) {
        // Brute Force Approach
        return lengthOfLongestSubstring1(s);
    }
};