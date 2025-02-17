class Solution {
public:
    int reverse(int x) {
        int reversedNum = 0;
        while(x) {
            int rem = x % 10;
            if(reversedNum > INT_MAX/10 || reversedNum < INT_MIN/10) {    
               return 0;
            }
            reversedNum = reversedNum*10 + rem;
            x /= 10;
        }
        return reversedNum;
    }
};