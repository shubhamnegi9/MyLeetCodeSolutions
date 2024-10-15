class Solution {
public:
    // Counting black balls going left to right and adding to swap
    long long minimumSteps1(string s) {
        long long swap = 0;
        int blackBalls = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') {
                blackBalls++;
            } else {
                swap += blackBalls;
            }
        }
        
        return swap;
    }
    
    long long minimumSteps(string s) {
        return minimumSteps1(s);
    }
};