class Solution {
public:
    int maxScore(string s) {
        int ones = count(s.begin(), s.end(), '1');
        int zeroes = 0;
        int ans = 0;
        for(int i = 0; i < s.size()-1; i++) {
            if(s[i] == '0') {
                zeroes++;
            }
            else {
                ones--;
            }
            ans = max(ans, zeroes + ones);
        }

        return ans;
    }
};