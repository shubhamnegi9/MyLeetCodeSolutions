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
    
    int findComplement(int num) {
        // Approach 1
        return findComplement1(num);
    }
};