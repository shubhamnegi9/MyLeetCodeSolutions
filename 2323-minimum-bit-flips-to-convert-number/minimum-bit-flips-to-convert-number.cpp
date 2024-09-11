class Solution {
public:
    
    // Approach 1: Counting different bits one by one
    int minBitFlips1(int start, int goal) {
        
        int count = 0;
        while(start > 0 || goal > 0) {
            
            if((start & 1) != (goal & 1)) {
                count++;
            }
            
            start >>= 1;
            goal >>= 1;
        }
        
        return count;
    }
    
    
    int minBitFlips(int start, int goal) {
        return minBitFlips1(start, goal);
    }
};