class Solution {
public:
    string compressedString(string word) {
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
};