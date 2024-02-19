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

    // Using Recursion
    bool isPowerOfTwoUsingRecursion(int n) {
        if(n <= 0)
            return false;
        if(n == 1)
            return true;
        
        return n%2==0 && isPowerOfTwoUsingRecursion(n/2);
    }

    // Using Bit Manipulation
    bool isPowerOfTwoUsingBits(int n) {
        // Corner Case
        if(n <= 0)
            return false;
        
        return ((n & (n-1)) == 0);
    }  

    // Using Built-In Function
    bool isPowerOfTwoBuiltInFunc(int n) {
        if(n<=0)
            return false;
        /* 
            __builtin_popcount(n) : Returns the count of set bits in n 
            If n is long long, then use : __builtin_popcountll(n)
        */
        int countOf1 =  __builtin_popcount(n);
        // If count of set bits is 1, then it is power of 2
        return countOf1 == 1;
    }

    // Shortcut Approach (Better not to tell in interviews)
    bool isPowerOfTwoShortcut(int n) {
        if(n<=0)
            return false;
        int mx = pow(2,30); // Maximum power of 2 in given constraint 

        // Any number which divides 2^30 will always be in power of 2
        return (mx%n) == 0; 
    }

    bool isPowerOfTwo(int n) {

        // return isPowerOfTwoUsingLoop(n);

        // return isPowerOfTwoUsingRecursion(n);

        // return isPowerOfTwoUsingBits(n);

        // return isPowerOfTwoBuiltInFunc(n);

        return isPowerOfTwoShortcut(n);
    }
};