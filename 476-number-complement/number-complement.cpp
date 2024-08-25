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
        unsigned int mask = (1U << numOfBits) - 1;   // Taking unsigned int as (1 << numOfBits) will make it go out of int bound
        return num ^ mask;
    }
    
        // Approach 3
    int findComplement3(int num) {
        int complement = 0;
        while(num) {
            complement |= !(num & 1);
        }
        return complement;
    }
    
    int findComplement(int num) {
        // Approach 1
        // return findComplement1(num);
        
        // Approach 2
        return findComplement2(num);
        
        // Approach 3
        // return findComplement2(num);
    }
};