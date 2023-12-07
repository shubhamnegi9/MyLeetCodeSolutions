class Solution {
public:
    string largestOddNumber(string num) {
        for(int i = num.size(); i >=0; i--) {
            // Finding rightmost odd char 
            if((num[i] - '0') % 2 == 1) {
                // Substring from start to this rightmost odd char will be largest
                return num.substr(0, i+1);
            }
        }
        return "";
    }
};