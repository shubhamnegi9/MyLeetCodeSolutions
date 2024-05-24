class Solution {
public:
    
    void solve(int i, vector<string>& words, vector<int> &freq, vector<int>& score, int n, int currScore, int &maxScore) {
        
        // Update maxScore
        maxScore = max(maxScore, currScore);
        
        // Base Case
        if(i >= n) {
            return;
        }
        
        // Storing freq in tempFreq to pass different freq maps in taken and not taken cases
        vector<int> tempFreq = freq;
        
        int j = 0;
        int tempScore = 0;
        
        // Checking if we can take this words[i]
        // Iterate in words[i]
        while(j < words[i].length()) {
            char ch = words[i][j];
            
            // Updating the score and map using letters of current word
            tempScore += score[ch-'a'];
            tempFreq[ch-'a']--;
            
            // If letter is not present in map, then we cannot take this words[i]
            if(tempFreq[ch-'a'] < 0)
                break;
            j++;
        }
        
        // FINDING THE MAXSCORE BY FIRST TAKING THE words[i] AND THEN NOT TAKING words[i]
        // Take words[i]
        if(j == words[i].length()) {    // If 'j' reaches till end of words[i] means we can take it
            // Pass index of next word (i+1), updated map (tempFreq), and updated score (currScore+tempScore)
            solve(i+1, words, tempFreq, score, n, currScore+tempScore, maxScore);
        }
        
        //Not Take words[i]
        // Pass index of next word (i+1), current map (freq), and current score (currScore)
        solve(i+1, words, freq, score, n, currScore, maxScore);
        
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26, 0);
        
        // Storing the frequency of every letter in map
        for(char ch: letters) {
            freq[ch-'a']++;
        }
        
        int maxScore = INT_MIN;
        int n = words.size();
        
        // Pass index of first word as 0, current map as freq, and current score 0
        solve(0, words, freq, score, n, 0, maxScore);
        
        return maxScore;
    }
};