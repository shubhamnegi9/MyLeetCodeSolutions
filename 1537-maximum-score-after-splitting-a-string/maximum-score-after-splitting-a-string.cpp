class Solution {
public:
    int maxScore(string s) {
        int ones = count(s.begin(), s.end(), '1');
        int zeroes = 0;
        int maxScore = 0;

        for(int i = 0; i < s.length()-1; i++) {     // Iterate till (s.length()-2) for left substring as the right substring cannot be empty
            if(s[i] == '0') {
                zeroes++;
            } else {
                ones--;
            }
            maxScore = max(maxScore, zeroes+ones);
        }
        
        return maxScore;
    }
};