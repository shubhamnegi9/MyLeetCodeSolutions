class Solution {
public:
    // Approach 1 : Using Loop
    int lengthOfLastWordUsingLoop(string s) {
        int n = s.length();

        int i = n-1;
        // Move 'i' until non-space character
        while(i >= 0 && s[i] == ' ') {
            i--;
        }

        int len= 0;
        // Move 'i' until space character and increase lenght
        while(i >= 0 && s[i] != ' ') {
            i--;
            len++;
        }

        return len;
    }

    int lengthOfLastWord(string s) {
        // Approach 1
        return lengthOfLastWordUsingLoop(s);
    }
};