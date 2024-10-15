class Solution {
public:
    // Counting black balls going left to right and adding to swap
    long long minimumSteps1(string s) {
        long long swap = 0;
        int blackBalls = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '1') {
                blackBalls++;
            } else {
                swap += blackBalls;
            }
        }
        
        return swap;
    }
    
    // Counting white balls going right to left and adding to swap
    long long minimumSteps2(string s) {
        long long swap = 0;
        int whiteBalls = 0;
        for(int i = s.length()-1; i >=0; i--) {
            if(s[i] == '0') {
                whiteBalls++;
            } else {
                swap += whiteBalls;
            }
        }
        return swap;
    }
    
    long long minimumSteps(string s) {
        // return minimumSteps1(s);
        return minimumSteps2(s);
    }
};