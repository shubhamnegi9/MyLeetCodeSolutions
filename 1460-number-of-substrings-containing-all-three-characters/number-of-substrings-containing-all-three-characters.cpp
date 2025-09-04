class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1)
    int numberOfSubstrings1(string s) {
        int n = s.length();
        int count = 0;

        for(int i = 0; i < n; i++) {
            vector<int> hash(3, 0);         // Reset hash array for each new starting character of substring 
            for(int j = i; j < n; j++) {
                hash[s[j] - 'a'] = 1;
                if(hash[0]+hash[1]+hash[2] == 3) {      // Found minimum window containing 'a', 'b', 'c' once 
                    count += (n-j);
                    break;
                }
            }
        }

        return count;
    }

    // Better Approach (Using sliding window)
    // T.C. = O(2n)
    // S.C. = O(3)
    int numberOfSubstrings2(string s) {
        int l = 0, r = 0, n = s.length(), count = 0;
        vector<int> freq(3, 0);

        while(r < n) {
            freq[s[r]-'a']++;

            // Keep shrinking window until valid substring is formed between window
            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                count += (n-r);

                freq[s[l]-'a']--;   // Decrease the freq of character at l before shrinking
                l++;
            }

            r++;
        }

        return count;
    }
    
    int numberOfSubstrings(string s) {
        // Brute Force Approach
        // return numberOfSubstrings1(s);

        // Better Approach
        return numberOfSubstrings2(s);
    }
};