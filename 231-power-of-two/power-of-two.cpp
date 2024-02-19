class Solution {
public:
    // Using Loop
    bool isPowerOfTwoUsingLoop(int n) {
        int ans = 1;
        for(int i = 0; i <= 30; i++) {
            if(ans == n)
                return true;
            if(ans < INT_MAX/2)
                ans*=2;
        }
        return false;
    }

    // Using Bit Manipulation
    bool isPowerOfTwoUsingBits(int n) {
        // Corner Case
        if(n <= 0)
            return false;
        
        return ((n & (n-1)) == 0);
    } 

    bool isPowerOfTwo(int n) {

        // return isPowerOfTwoUsingLoop(n);

        return isPowerOfTwoUsingBits(n);
    }
};