class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1;  
        unordered_map<char, char> mp2; 

        int m = s.length();

        for(int i = 0; i < m; i++) {
            char ch1 = s[i];
            char ch2 = t[i];

            // If character of 's' is already found in map and it is not mapped to character of 't', or
            // If character of 't' is already found in map and it is not mapped to character of 's'
            if((mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2) || 
                mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1) {
                    return false;
            }

            // Map character of s to t
            // Map character of t to s
            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }

        return true;
    }
};