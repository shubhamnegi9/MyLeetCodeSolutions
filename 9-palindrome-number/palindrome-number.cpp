class Solution {
public:
    bool isPalindrome(int x) {
        int reversed = 0;
        int temp = x;
        while(temp) {
            int rem = temp % 10;
            if(reversed > INT_MAX/10 || reversed < INT_MIN/10) {
                break;
            }
            reversed = reversed*10 + rem;
            temp /= 10; 
        }
        return (x >= 0 && reversed == x);
    }
};