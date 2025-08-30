class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(256)
    int lengthOfLongestSubstring1(string s) {
        int n = s.length();
        int maxLen = 0;
        for(int i = 0; i < n; i++) {
            int hash[256];    
            memset(hash, 0, sizeof(hash)); // Reset/define the hash array whenever we have new starting point of substring
            for(int j = i; j < n; j++) {
                if(hash[s[j]] == 1)     // s[j] is repeating character
                    break;
                
                int len = j-i+1;
                maxLen = max(maxLen, len);
                hash[s[j]] = 1;
            }
        }

        return maxLen;
    }
    
    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(256)
    int lengthOfLongestSubstring2(string s) {
        int n = s.length();
        int maxLen = 0;
        int l = 0, r = 0;
        int hash[256];
        memset(hash, -1, sizeof(hash));    

        while(r < n) {
            if(hash[s[r]] != -1) {      // s[r] is present in hash array
                if(hash[s[r]] >= l) {   // s[r] is repeating character
                    l = hash[s[r]]+1;       // move l to one position ahead of hash[s[r]]
                }
            }

            int len = r-l+1;
            maxLen = max(maxLen, len);
            hash[s[r]] = r;             // Store index r of char at s[r] in hash array
            r++;
        }

        return maxLen;
    }
    
    // Another Optimal Approach
    // T.C. = O(n)
    // S.C. = O(256)
    int lengthOfLongestSubstring3(string s) {
        int n = s.length();
        int maxLen = 0;
        int l = 0, r = 0;
        int hash[256];
        memset(hash, 0, sizeof(hash));    

        while(r < n) {
            while(l < r && hash[s[r]] == 1) {   // Move l ahead until hash[s[r]] becomes 0
                hash[s[l]] = 0;
                l++;
            }

            int len = r-l+1;
            maxLen = max(maxLen, len);
            hash[s[r]] = 1;             
            r++;
        }

        return maxLen;
    }

    int lengthOfLongestSubstring(string s) {
        // Brute Force Approach
        // return lengthOfLongestSubstring1(s);

        // Optimal Approach
        // return lengthOfLongestSubstring2(s);

        // Another Optimal Approach
        return lengthOfLongestSubstring3(s);
    }
};