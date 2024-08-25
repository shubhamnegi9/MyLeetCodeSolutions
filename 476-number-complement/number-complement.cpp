class Solution {
public:
    
    // Approach 1
    int findComplement1(int num) {
        int numOfBits = log2(num)+1;
        for(int i = 0; i < numOfBits; i++) {
            num ^= (1 << i);
        }
        
        return num;
    }
    
    // Approach 2
    int findComplement2(int num) {
        int numOfBits = log2(num)+1;
        unsigned int mask = (1U << numOfBits) - 1;   // Taking mask as unsigned int and making 1 as unsigned int as (1 << numOfBits) will make it go out of int bound
        return num ^ mask;
    }
    
        // Approach 3
    int findComplement3(int num) {
        int complement = 0;
        int i = 0;
        while(num) {
            if(!(num&1)) {  // If the bit at rightmost position is 0, then we need to flip it in its complement 
                 complement |= (1 << i);
            }
            i++;
            num >>= 1;   // right shifting num
        }
        return complement;
    }
    
    int findComplement(int num) {
        // Approach 1
        // return findComplement1(num);
        
        // Approach 2
        // return findComplement2(num);
        
        // Approach 3
        return findComplement3(num);
    }
};