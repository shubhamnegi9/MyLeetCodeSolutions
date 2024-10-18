class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        // Inserting first character of pattern at start of text
        string first = pattern[0] + text;
        // Inserting last character of pattern at end of text
        string last = text + pattern[1];
        
        // Finding count of subsequence of pattern in 'first' string
        long long countPatternFirstChar = 0;
        long long firstSubsequence = 0;
        for(int i = 0; i < first.length(); i++) {
            if(first[i] == pattern[0]) {
                countPatternFirstChar++;
            } else if(first[i] == pattern[1]){
                firstSubsequence += countPatternFirstChar;
            }
        }
        
        // Finding count of subsequence of pattern in 'last' string
        long long countPatternSecondChar = 0;
        long long lastSubsequence = 0;
        for(int i = last.length()-1; i >= 0; i--) {
            if(last[i] == pattern[1]) {
                countPatternSecondChar++;
            } else if(last[i] == pattern[0]){
                lastSubsequence += countPatternSecondChar;
            }
        }
        
        // Addition case to handle 
        // If both the characters of pattern are equal 
        if(pattern[0] == pattern[1]) {
            long long m = countPatternFirstChar;
            return m*(m-1)/2;
        }
        
        return max(firstSubsequence, lastSubsequence);
    }
};