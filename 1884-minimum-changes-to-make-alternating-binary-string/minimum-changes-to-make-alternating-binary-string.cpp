class Solution {
public:
    int minOperations(string s) {
        int count1 = 0, count2 = 0;
        int start = s[0] - '0';
        for(int i = 0; i < s.size(); i++) {
            if(s[i] - '0' != start) {
                count1++;
            }
            start = !start;
            if(s[i] - '0' != start) {
                count2++;
            }
        }
        return min(count1, count2);
    }
};