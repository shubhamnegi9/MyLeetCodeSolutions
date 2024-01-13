class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> mpp;
        for(char ch: t) {
            mpp[ch]++;
        }

        for(char ch: s) {
            mpp[ch]--;
        }

        int steps = 0;
        for(auto it: mpp) {
            if(it.second > 0) {
                // cout << it.first << " " << it.second << endl;
                steps+=it.second;
            }
        }

        return steps;
    }
};