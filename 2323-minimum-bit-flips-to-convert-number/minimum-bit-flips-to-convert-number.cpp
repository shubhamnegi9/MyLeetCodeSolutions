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
    
    // Approach-2: Using XOR
    int minBitFlips2(int start, int goal) {
        
        int XOR = start ^ goal;
        int count = 0;
        
        while(XOR) {
            count += (XOR & 1);
            XOR >>= 1;
        }
        
        return count;
    }
    
    // Approach-3: Using Brian Kernighan’s Algorithm 
    int minBitFlips3(int start, int goal) {
    
        int XOR = start ^ goal;
        int count = 0;
        
        while(XOR) {
            XOR = XOR & (XOR-1);
            count++;
        }
        
        return count;
    }
    
    
    int minBitFlips(int start, int goal) {
        // Approach 1
        // return minBitFlips1(start, goal);
        
        // Approach 2
        // return minBitFlips2(start, goal);
        
        // Approach 3
        return minBitFlips3(start, goal);
    }
};