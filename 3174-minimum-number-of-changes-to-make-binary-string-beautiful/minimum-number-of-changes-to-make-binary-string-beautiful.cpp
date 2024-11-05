class Solution {
public:
    // Approach 1: Greedy
    // T.C. = O(n)
    // S.C. = O(1)
    int minChanges1(string s) {
        int n = s.length();
        int count = 0;
        int changes = 0;
        char ch = s[0];
        
        for(int i = 0; i < n; i++) {
            // Current character same as previous character. 
            // Increment count of current character and continue to next character
            if(s[i] == ch) {
                count++;
                continue;
            }
            
            // If coming here, it means current character is different than previous
            
            // If count of previous character is even, we need to start new sequence from here
            // Reset count to 1.
            if(count%2 == 0) {
                count = 1;
            } 
            // If count of previous character is odd, then we need to change current character to previous character
            // Increment change by 1 and reset count to 0 as current character is not helping in creating any new sequence.
            else {
                changes++;
                count = 0;
            }
            
            // Update 'ch' whenever current character is different than previous
            ch = s[i];
        }
        
        return changes;
    }
        
    // Approach 2: Greedy Optimized
    // T.C. = O(n)
    // S.C. = O(1)
    int minChanges2(string s) {
        int n = s.length();
        int count = 0;
        
        // Break string into substrings of 2 length and increment count if they are not equal
        for(int i = 0; i < n; i+=2) {
            if(s[i] != s[i+1])
                count++;
        }
        
        return count;
    }
    
    int minChanges(string s) {
       // Approach 1
       return minChanges1(s); 
       
       // Approach 2 
       // return minChanges2(s); 
    }
};