class Solution {
public:
    
    // Brute Force by rotating the string each time and checking
    // T.C. = O(n^2)
    // S.C. = O(1)
    bool rotateString1(string s, string goal) {
        int n = s.length();
        int m  = goal.length();
        
        if(n != m)
            return false;
        
        for(int i = 0; i < n; i++) {
            if(s == goal)
                return true;
            
            // Rotating the string to left
            char temp = s[0];    
            for(int j = 0; j < n; j++) {
                s[j] = s[j+1];
            }
            s[n-1] = temp;
        }
        
        return false;
    }
    
    // Brute Force by rotating the string each time using STL
    // T.C. = O(n^2)
    // S.C. = O(1)
    bool rotateString2(string s, string goal) {
        int n = s.length();
        int m  = goal.length();
        
        if(n != m)
            return false;
        
        for(int i = 0; i < n; i++) {
            if(s == goal)
                return true;
            
            // Rotating the string to left using rotate STL
            rotate(s.begin(), s.begin()+1, s.end());
        }
        
        return false;
    }
    
    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(2*n) = O(n)
    bool rotateString3(string s, string goal) {
        int n = s.length();
        int m  = goal.length();
        
        if(n != m)
            return false;
        
        string concatenated = s+s;
        if(concatenated.find(goal) != string::npos) {
            return true;
        }
        
        return false;
    }
    
    bool rotateString(string s, string goal) {
       // return rotateString1(s, goal);
        
        // return rotateString2(s, goal);
        
        return rotateString3(s, goal);
    }
};