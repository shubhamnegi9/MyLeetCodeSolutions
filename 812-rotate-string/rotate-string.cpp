class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m  = goal.length();
        
        if(n != m)
            return false;
        
        for(int i = 0; i < n; i++) {
            if(s == goal)
                return true;
            char temp = s[0];    
            for(int j = 0; j < n; j++) {
                s[j] = s[j+1];
            }
            s[n-1] = temp;
        }
        
        return false;
    }
};