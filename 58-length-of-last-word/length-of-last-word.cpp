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
        // Move 'i' until space character and increase length
        while(i >= 0 && s[i] != ' ') {
            i--;
            len++;
        }

        return len;
    }

    // Approach 2: Using STL
    int lengthOfLastWordUsingSTL(string s) {

        // find_last_not_of(' ') : Returns first index from last character which is not a space
        // find_last_not_of(' ') + 1: Returns index of first space character from last
        int index = s.find_last_not_of(' ') + 1;
        // Erase all characters starting from index till end
        s.erase(index);

        // find_last_of(' ') : Returns first index from last character which is a space
        int last_space_index = s.find_last_of(' ');
        
        return last_space_index == string::npos ? s.length() : s.length() - last_space_index - 1;
    } 

    int lengthOfLastWord(string s) {
        // Approach 1
        // return lengthOfLastWordUsingLoop(s);

        // Approach 2
        return lengthOfLastWordUsingSTL(s);
    }
};