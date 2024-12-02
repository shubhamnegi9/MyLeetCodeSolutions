class Solution {
public:
    // Approach 1
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
    
    // Approach 2: Using iStringStream 
    int isPrefixOfWord2(string sentence, string searchWord) {
        string word = "";
        vector<string> wordList;
        istringstream iss(sentence);
        
        while(iss >> word) {
            wordList.push_back(word);
        }
        
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
    
    // Approach 3: Using iStringStream and find() function 
    int isPrefixOfWord3(string sentence, string searchWord) {
        string word = "";
        istringstream iss(sentence);
        int index = 0;
        
        while(iss >> word) {
            index++;
            if(word.find(searchWord) == 0) {    // find() returns 0 if searchWord is at the start
                return index;
            }
        }
    
        return -1;
    }
    
    

    int isPrefixOfWord(string sentence, string searchWord) {
        // Approach 1
        // return isPrefixOfWord1(sentence, searchWord);
        
        // Approach 2: Using iStringStream 
        // return isPrefixOfWord2(sentence, searchWord);
        
        // Approach 3: Using iStringStream and find() function 
        return isPrefixOfWord3(sentence, searchWord);
    }
};