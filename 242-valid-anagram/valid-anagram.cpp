class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> hash;

        for(int i = 0; i < s.size(); i++) {
            hash[s[i]]++;
        }

        // for(auto it : hash) {
        //     cout << it.first << "->" << it.second << " ";
        // }
        // cout << endl;

        for(int i = 0; i < t.size(); i++) {
            hash[t[i]]--;
        }

        // for(auto it : hash) {
        //     cout << it.first << "->" << it.second << " ";
        // }
        // cout << endl;

        for(auto it: hash) {
            if(it.second != 0)
                return false;
        }

        return true;
    }
};