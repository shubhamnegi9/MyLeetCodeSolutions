class Solution {
public:
    vector<string> split(string s) {
        istringstream iss(s);
        string word;
        vector<string> wordList;
        while(iss >> word) {
            wordList.push_back(word);
        }
        return wordList;
    }
    
    // Approach 1: By spliting the sentence 
    // T.C. = O(n)
    // S.C. = O(n)
    bool isCircularSentence1(string sentence) {
        vector<string> wordList = split(sentence);
        int n = wordList.size();
        
        char last = wordList[n-1].back();
        
        for(int i = 0; i < n; i++) {
            if(last != wordList[i].front())
                return false;
            last = wordList[i].back();
        }
        
        return true;
    }
    
    // Approach 2: Space Optimized Approach
    // T.C. = O(n)
    // S.C. = O(1)
    bool isCircularSentence2(string sentence) {
        int n = sentence.length();
        for(int i = 0; i < n; i++) {
            if(sentence[i] == ' ' && sentence[i-1] != sentence[i+1])
                return false;
        }
        
        return sentence[0] == sentence[n-1];
    }
    
    bool isCircularSentence(string sentence) {
        // Approach 1: By spliting the sentence 
        // return isCircularSentence1(sentence);
        
        // Approach 2: Space Optimized Approach
        return isCircularSentence2(sentence);
    }
};