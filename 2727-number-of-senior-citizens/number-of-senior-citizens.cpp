class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(string str: details) {
            // The easiest way to convert a single character to the integer it represents is to subtract the value of '0'
            int age = (str[11] - '0') * 10 + (str[12] - '0'); 
            if(age > 60) {
                count++;
            }
        }
        
        return count;
    } 
};