class Solution {
public:
    // Approach 1
    // T.C. = O(n)
    // S.C. = O(1)
    string compressedString1(string word) {
        int count = 1;
        int n = word.length();
        
        string result = "";
        for(int i = 1; i < n; i++) {
            if(word[i] == word[i-1]) {
                count++;
                if(count > 9) {
                    result+=to_string(count-1);
                    result+=word[i-1];
                    count = 1;
                }
                    
            } else {
                result+=to_string(count);
                result+=word[i-1];
                count = 1; 
            }
        }
        
        result+=to_string(count);
        result+=word[n-1];
        return result;
    }
    
    // Approach 2
    // T.C. = O(n)
    // S.C. = O(1)
    string compressedString2(string word) {
        int n = word.length();
        int i = 0;
        string result = "";
        while(i < n) {
            int count = 1;
            while(i < n-1 && count < 9 && word[i] == word[i+1]) {   // Count and skips all same characters
                count++;
                i++;
            }
            result += (to_string(count) + word[i]);
            i++;
        }
        
        return result;
    }
    
    string compressedString(string word) {
        // Approach 1
        // return compressedString1(word);
        
        // Approach 2
        return compressedString2(word);
    }
};