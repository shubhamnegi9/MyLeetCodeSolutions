class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        int reversed = 0;
        while(temp) {
            int digit = temp % 10;
            if(reversed < INT_MIN/10 || reversed > INT_MAX/10)
                return false;
            reversed = reversed*10 + digit;
            temp /= 10;
        }

        return x >= 0 && reversed == x;
    }
};