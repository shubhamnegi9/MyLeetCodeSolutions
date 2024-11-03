class Solution {
public:
    bool isPalindrome(int x) {
        int rev = 0;
        int temp = x;
        while(temp) {
            if(rev > INT_MIN/10 && rev < INT_MAX/10)
                rev = rev*10 + (temp%10);
            temp/=10;
        }
        
        return (rev >= 0 && x == rev);
    }
};