class Solution {
public:
    bool closeStrings(string word1, string word2) {
        /*
            Intuition:
            1. If a character is present in word1 then it will also be present in word2.
               If a character is not present in word1 then it will also not be present in word2.
               No extra characters will be used when transforming.
            2. Order of frequency of characters in both words do not matter. What matters is whether
               those frequencies are same or not. We can sort the frequencies stored for both words
               and can check.
            3. If both the words have different length, then we can never transform them
        */

        int m = word1.length();
        int n = word2.length();
        vector<int> freq1(26);  // Hash array for storing frequency of characters in word1
        vector<int> freq2(26);  // Hash array for storing frequency of characters in word2
        
        // Point 3
        if(m != n)
            return false;
        
        // Storing frequencies for both the words
        // Note that since size of both words are same, so we can store frequency in same loop
        for(int i = 0; i < m; i++) {
            freq1[word1[i] - 'a']++;
            freq2[word2[i] - 'a']++;
        }

        // Point 1
        for(int i = 0; i < 26; i++) {
            // If a character is present in word1 then it will also be present in word2
            if(freq1[i] != 0 && freq2[i] != 0) {
                continue;
            }
            // If a character is not present in word1 then it will also not be present in word2
            if(freq1[i] == 0 && freq2[i] == 0) {
                continue;
            }
            // Otherwise return false
            return false;
        }

        // Point2
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        // Checking for same frequencies
        return (freq1 == freq2);
    }
};