class Solution {
public:
    // Approach 1 
    int hammingWeight1(int n) {
        int count = 0;
        while(n > 1) {
            count += (n&1);     // Equivalent to:  if(n%2==1) count++
            n >>= 1;            // Equivalent to:  n = n/2; 
        }
        if(n==1)
            count++;

        return count;
    }

    int hammingWeight2(int n) {
        int count = 0;
        while(n) {
            n = n & (n-1);
            count++; 
        }

        return count;
    }
    
    int hammingWeight(int n) {
        // Approach 1 
        // return hammingWeight1(n);

        // Approach 2
        return hammingWeight2(n);

        // Approach 3 (Using STL function)
        // return __builtin_popcount(n);

    }
};