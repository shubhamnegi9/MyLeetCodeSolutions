class Solution {
public:
    int isPrefixOfWord1(string sentence, string searchWord) {
        string word = "";
        vector<string> wordList;
        // Breaking sentence into list of words
        for(char ch: sentence) {
            if(ch != ' ') {
                word+=ch;
            } else {
                wordList.push_back(word);
                word = "";
            }
        }
        wordList.push_back(word);   // For pushing last word in wordList
        
        // Checking if searchWord is prefix of any word in wordList
        int l = searchWord.length();
        int res = -1;
        for(int i = 0; i < wordList.size(); i++) {
            if(wordList[i].length() >= l && wordList[i].substr(0, l) == searchWord) {
                res = i+1;
                break;
            }
        }
    
        return res;
    }

    int isPrefixOfWord(string sentence, string searchWord) {
        return isPrefixOfWord1(sentence, searchWord);
    }
};