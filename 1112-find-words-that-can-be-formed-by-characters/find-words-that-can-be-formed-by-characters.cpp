class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> hash(26, 0);
        for(auto ch: chars) {
            hash[ch - 'a']++;
        }
        // for(int i = 0; i < 26; i++) {
        //     cout << hash[i] << " ";
        // }
        // cout << endl;
        int res = 0;
        for(auto word: words) {
            int flag = 0;
            vector<int> temp = hash;
            // cout << word << " ";
            for(auto ch: word) {
                // cout << ch << " ";
                if(temp[ch - 'a'] > 0) {
                    temp[ch - 'a']--;
                }
                else {
                    // string cannot be formed
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) {
                // cout << "Contains: " <<  word << endl;
                res += word.length();
            }
        }
        // cout << endl;
        // cout << "res= " << res << endl;
        return res;
    }
};