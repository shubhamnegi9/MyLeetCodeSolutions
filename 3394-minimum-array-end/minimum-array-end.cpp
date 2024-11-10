class Solution {
public:
    long long minEnd(int n, int x) {
        long long num = x;
        
        for(int i = 1; i < n; i++) {
            
            // (num+1) | x gives next number after num which on Bitwise AND with x will give x
            num = (num+1) | x;  
            
        }
        
        return num;
    }
};