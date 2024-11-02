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
    
    bool isCircularSentence(string sentence) {
        vector<string> wordList = split(sentence);
        int n = wordList.size();
        
        if(n==1) {
            string word = wordList[0];
            return word[0] == word[word.length()-1];
        }
        
        bool isCircular = true;
        
        string firstWord = wordList[0];
        string lastWord = wordList[n-1];
        if(firstWord[0] != lastWord[lastWord.length()-1])
            isCircular = false;
        
        if(isCircular) {
            for(int i = 0; i < n-1; i++) {
                string currWord = wordList[i];
                string nextWord = wordList[i+1];
                if(currWord[currWord.length()-1] != nextWord[0]) {
                    isCircular = false;
                    break;
                }
            }
        }
        
        return isCircular;
    }
};