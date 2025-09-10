class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n^2) * O(m)
    // S.C. = O(256) for hash array
    string minWindow1(string s, string t) {
        int n = s.length(), m = t.length();
        int sIndex = -1, minLen = INT_MAX;

        for(int i = 0; i < n; i++) {
            // Reset hashArr as well as count for substring with new starting point
            vector<int> hashArr(256, 0);
            int count = 0;
            
            // Maintain the count of characters in hashArr b/w i to n-1
            for(int j = 0; j < m; j++) {
                hashArr[t[j]]++;
            }

            for(int j = i; j < n; j++) {
                // Before reducing count of s[j], check if count of s[j] > 0, then increment count
                if(hashArr[s[j]] > 0) {
                    count++;
                }
                hashArr[s[j]]--;

                if(count == m) {
                    // Update minLen and sIndex
                    if(j-i+1 < minLen) {
                        minLen = j-i+1;
                        sIndex = i;
                    }
                }
            }
        }

        return (sIndex == -1) ? "" : s.substr(sIndex, minLen);
    }

    // Optimal Approach
    // T.C. = O(2n) for sliding window + O(m) for store the count of characters of t in map
    // S.C. = O(256) for map/ hashArr
    string minWindow2(string s, string t) {
        int n = s.length(), m = t.length();
        int l = 0, r = 0, count = 0, sIndex = -1, minLen = INT_MAX;
        unordered_map<int, int> mpp;    // Can use hashArr also

        // Store the count of characters of t in map
        for(int i = 0; i < m; i++) {
            mpp[t[i]]++;
        }

        while(r < n) {
            // Before reducing count of s[r], check if count of s[r] > 0, then increment count
            if(mpp[s[r]] > 0) {
                count++;
            }
            mpp[s[r]]--;

            // Shrinking the window until count == m
            while(count == m) {
                // Update minLen and sIndex
                if(r-l+1 < minLen) {
                    minLen = r-l+1;
                    sIndex = l;
                }

                mpp[s[l]]++;
                // After increasing count of s[l], check if count of s[l] > 0, then decrement count
                if(mpp[s[l]] > 0) {
                    count--;
                }
                l++;
            }

            r++;
        }

        return (sIndex == -1) ? "" : s.substr(sIndex, minLen);
    }
    
    string minWindow(string s, string t) {
        // Brute Force Approach
        // return minWindow1(s, t);

        // Optimal Approach
        return minWindow2(s, t);
    }
};