class Solution {
public:
    int getLucky(string s, int k) {
        // Conversion
        string str = "";
        for(char ch: s) {
            str+=to_string(ch-'a'+1);
        }
        
        // Transformation
        int sum = 0;
        while(k) {
            for(char ch: str) {
                sum += ch-'0';
            }
            str = to_string(sum);
            sum = 0;
            k--;
        }
        
        return stoi(str);
    }
};