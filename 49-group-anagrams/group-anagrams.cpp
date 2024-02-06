class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;

        for(string &word: strs) {
            string tempWord = word; 
            sort(word.begin(), word.end());
            mpp[word].push_back(tempWord);
        }

        vector<vector<string>> result;

        for(auto it = mpp.begin(); it != mpp.end(); it++) {
            vector<string> entry = it->second;
            result.push_back(entry);
        }

        return result;
    }
};