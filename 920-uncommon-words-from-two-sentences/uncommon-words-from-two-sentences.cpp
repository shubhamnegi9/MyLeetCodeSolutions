class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordsMap;
        
        stringstream ss1(s1);
        string token = "";
        
        while(ss1 >> token) {
            wordsMap[token]++;
        }
        
        stringstream ss2(s2);
        while(ss2 >> token) {
            wordsMap[token]++;
        }
        
        vector<string> result;
        for(auto it: wordsMap) {
            if(it.second == 1) {
                result.push_back(it.first);
            }
        }
        
        return result;
    }
};