class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(26) for hash array
    int characterReplacement1(string s, int k) {
        int n = s.length(), maxFreq = 0, maxLen = 0;

        for(int i = 0; i < n; i++) {
            vector<int> hashArr(26, 0);     // Reset the hashArray everytime for new starting point of substring
            for(int j = i; j < n; j++) {
                hashArr[s[j]-'A']++;
                maxFreq = max(maxFreq, hashArr[s[j]-'A']);
                int len = (j-i+1);
                int conversions = len - maxFreq;
                if(conversions <= k) {
                    maxLen = max(maxLen, len);
                } else {
                    break;      // Break from adding further characters to invalid substring
                }
            }
        }

        return maxLen;
    }

    // Better Approach
    // T.C. = O(n + n*26)
    // S.C. = O(26) for hash array
    int characterReplacement2(string s, int k) {
        int n = s.length(), maxFreq = 0, maxLen = 0, l = 0, r = 0;
        vector<int> hashArr(26, 0);

        while(r < n) {
            hashArr[s[r]-'A']++;
            maxFreq = max(maxFreq, hashArr[s[r]-'A']);
            
            // Note: Don't store ((r-l+1) - maxFreq) in some variable conversions and use it later. Because it will not change conversions after window is shrinked

            while((r-l+1) - maxFreq > k) {  // Shrinking the window
                hashArr[s[l]-'A']--;
                
                // Note: We can skip below updation of maxFreq while shrinking window
                maxFreq = 0;
                for(int i = 0; i < 26; i++) {
                    maxFreq = max(maxFreq, hashArr[i]);
                }

                l++;
            }

            if((r-l+1) - maxFreq <= k) {
                maxLen = max(maxLen, r-l+1);
            }
            r++;
        }

        return maxLen;
    }

    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(26) for hash array
    int characterReplacement3(string s, int k) {
        int n = s.length(), maxFreq = 0, maxLen = 0, l = 0, r = 0;
        vector<int> hashArr(26, 0);

        while(r < n) {
            hashArr[s[r]-'A']++;
            maxFreq = max(maxFreq, hashArr[s[r]-'A']);
            
            // Note: Don't store ((r-l+1) - maxFreq) in some variable conversions and use it later. Because it will not change conversions after window is shrinked

            if((r-l+1) - maxFreq > k) {  // Shrinking the window only once
                hashArr[s[l]-'A']--;
                l++;
            }

            if((r-l+1) - maxFreq <= k) {
                maxLen = max(maxLen, r-l+1);
            }
            r++;
        }

        return maxLen;
    }
    
    int characterReplacement(string s, int k) {
        // Brute Force Approach
        // return characterReplacement1(s, k);

        // Better Approach
        // return characterReplacement2(s, k);

        // Optimal Approach
        return characterReplacement3(s, k);
    }
};