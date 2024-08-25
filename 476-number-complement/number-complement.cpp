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
        unsigned int mask = pow(2,numOfBits)-1;
        return num ^ mask;
    }
    
    int findComplement(int num) {
        // Approach 1
        return findComplement1(num);
        
        // Approach 2
        return findComplement2(num);
    }
};