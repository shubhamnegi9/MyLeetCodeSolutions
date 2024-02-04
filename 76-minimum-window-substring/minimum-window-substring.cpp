class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.length();


        if(t.size() > n)    // s cannot contain all chars of t
            return "";  
        
        int i = 0, j = 0;
        int requiredCount = t.length();
        int minWindowSize = INT_MAX;
        int start_i = 0;

        unordered_map<char, int> mpp;
        // Storing count of all chars of t in map
        for(char &ch: t) {
            mpp[ch]++;
        }

        while(j < n) {
            if(mpp[s[j]] > 0) {
                requiredCount--;
            }
            mpp[s[j]]--;

            while(requiredCount == 0) {     // Window found
                int currWindowSize = j-i+1;
                if(currWindowSize < minWindowSize) {
                    minWindowSize = currWindowSize;  // Finding min window size
                    start_i = i;    // Initialize start_i as start index of the min size window only 
                }

                mpp[s[i]]++;

                if(mpp[s[i]] > 0) {
                    requiredCount++;
                }
                i++;    // Shrink Window
            }

            j++;    // Expand Window
        }

        return (minWindowSize == INT_MAX) ? "" : s.substr(start_i, minWindowSize);
        // s.substr(start_i, minWindowSize) : Return 'minWindowSize' characters from start_i 
    }
};