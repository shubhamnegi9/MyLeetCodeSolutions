class Solution {
public:
    bool isUgly(int n) {
        /*
            Note:
            1 is an Ugly Number because 1 can be written as (2^0 * 3^0 * 5^0)
        */
        while(n > 1) {
            if(n%2 == 0)
                n /= 2;     // Keep dividing by 2 if divisible by 2
            else if(n%3==0)
                n /= 3;     // Keep dividing by 3 if divisible by 3
            else if(n%5==0)
                n /= 5;     // Keep dividing by 5 if divisible by 5
            else
                return false;   // If not divisible by 2, 3 or 5 then not ugly number
        }
        
        return (n==1);      // After dividing if n becomes 1, then it is ugly number
    }
};