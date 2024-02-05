class Solution {
public:
    int firstUniqChar(string s) {
        int hash[26];

        for(char &ch: s) {
            hash[ch-'a']+=1;
        }

        for(int i = 0; i < s.size(); i++) {
            if(hash[s[i]-'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};