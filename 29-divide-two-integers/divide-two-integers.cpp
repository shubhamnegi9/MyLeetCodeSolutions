class Solution {
public:
    // Brute Force Approach
    // T.C. = O(dividend) if divisor = 1
    // S.C. = O(1)
    int divide1(int dividend, int divisor) {
        // Handle overflow
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;

        // Edge Case
        if(divisor == dividend)
            return 1;
        if(divisor == -((long)dividend))
            return -1;

        long sum = 0, quotient = 0;
        bool sign = true;
        
        // Handling negative divison scenario
        if((dividend < 0 && divisor >= 0) || (dividend >= 0 && divisor < 0)) {
            sign = false;
        }

        // Taking absolute value as long
        long n = abs(long(dividend));
        long d = abs(long(divisor));

        while(sum+d <= n) {
            quotient++;
            sum+=d;
        }

        // Checking overflow as per problem 
        if(quotient == (1<<31) && sign)
            return INT_MAX;

        if(quotient == (1<<31) && !sign) 
            return INT_MIN; 

        return sign ? quotient : -quotient;
    }
    
    int divide2(int dividend, int divisor) {
        // Handle overflow
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;

        // Edge Case
        if(divisor == dividend)
            return 1;
        if(divisor == -((long)dividend))
            return -1;

        // Handling negative divison scenario
        bool sign = true;
        if((dividend < 0 && divisor >= 0) || (dividend >= 0 && divisor < 0)) {
            sign = false;
        }

        // Taking absolute value as long
        long n = abs(long(dividend));
        long d = abs(long(divisor));

        long quotient = 0;

        while(n >= d) {
            int count = 0;
            while(d << (count+1) <= n) {
                count++;
            }

            quotient += (1 << count);
            n -= (d << count);
        }

        // Checking overflow as per problem 
        if(quotient == (1<<31) && sign)
            return INT_MAX;

        if(quotient == (1<<31) && !sign) 
            return INT_MIN; 

        return sign ? quotient : -quotient;
    }
    
    int divide(int dividend, int divisor) {
        // Brute Force Approach
        // return divide1(dividend, divisor);

        // Optimal Approach
        return divide2(dividend, divisor);
    }
};