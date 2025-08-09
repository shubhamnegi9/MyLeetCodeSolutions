class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        int m = n;
        long N = abs((long)n);      // Convert n to long to find absolute value

        while(N > 0) {
            if(N%2 == 1) {
                ans = ans * x;
                N = N-1;
            } else {
                x = x*x;
                N = N/2;
            }
        }

        if(m < 0)
            return (1.0/ans);
        
        return ans;
    }
};