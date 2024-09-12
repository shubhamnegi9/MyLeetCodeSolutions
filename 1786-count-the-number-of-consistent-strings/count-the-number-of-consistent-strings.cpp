class Solution {
public:
    
    // Using Map
    int countConsistentStrings1(string allowed, vector<string>& words) {
        unordered_map<char, bool> allowedMap;
        
        for(char ch: allowed) {
            allowedMap[ch] = true;
        }
        
        int count = 0;
        for(string str: words) {
            bool isConsistent = true;
            for(char ch: str) {
                if(!allowedMap[ch]) {
                    isConsistent = false;
                    break;
                }
            }
            if(isConsistent) {
                count++;
            }
        }
        
        return count;
    }
    
    int countConsistentStrings(string allowed, vector<string>& words) {
       
        // Using Map
        return countConsistentStrings1(allowed, words);
    }
};