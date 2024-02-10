class Solution {
public:
    bool isPalindromic(string s) {
        int i = 0, j = s.size()-1;
        while(i <= j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }

    int countSubstrings(string s) {
        int n = s.size();

        int count = 0;
        for(int i = 0; i < n; i++) {
            string temp = "";
            for(int j = i; j < n; j++) {
                temp+=s[j];
                if(isPalindromic(temp))
                    count++;
            }
        }

        return count;
    }
};