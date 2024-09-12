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
    
    // Using Vector
    int countConsistentStrings2(string allowed, vector<string>& words) {
        vector<bool> allowedVector(26, false);
        
        for(char ch: allowed) {
            allowedVector[ch-'a'] = true;
        }
        
        int count = 0;
        for(string str: words) {
            bool isConsistent = true;
            for(char ch: str) {
                if(!allowedVector[ch-'a']) {
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
    
    // Using Set
    int countConsistentStrings3(string allowed, vector<string>& words) {
        set<char> allowedSet(allowed.begin(), allowed.end());
        
        int count = 0;
        for(string str: words) {
            bool isConsistent = true;
            for(char ch: str) {
                if(allowedSet.find(ch) == allowedSet.end()) {   // Character not found in set
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
        // return countConsistentStrings1(allowed, words);
        
        // Using Vector
        // return countConsistentStrings2(allowed, words);
        
        // Using Set
        return countConsistentStrings3(allowed, words);
    }
};