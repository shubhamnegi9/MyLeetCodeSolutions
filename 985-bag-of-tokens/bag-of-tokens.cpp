class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();

        // Sort the token array
        sort(tokens.begin(), tokens.end());

        int i = 0, j = n-1;
        int score = 0, maxScore = 0;

        while(i <= j) {
            if(power >= tokens[i]) {
                // Loose power and gain score
                power -= tokens[i];
                score+=1;
                maxScore = max(maxScore, score);
                i++;
            }
            else if(score >= 1) {
                // Gain power and loose score
                power += tokens[j];
                score-=1;
                j--;
            }
            else {
                return maxScore;
            }
        }

        return maxScore;
    }
};