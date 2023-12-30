class Solution {
public:
    bool makeEqual(vector<string>& words) {
        // Using Unordered Map
        unordered_map<char,int> count;
        int n = words.size();

        for(string str: words) { 
            for(char ch: str) {
                count[ch]++;
            }
        }

        for(auto it: count) {
            int freq = it.second;
            // If count of character is not divisible
            // by n, then the character cannot be 
            // distributed among each word in words array 
            if(freq % n != 0) {
                return false;
            }
        }

        return true;
    }
};