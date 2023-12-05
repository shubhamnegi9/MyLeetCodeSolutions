class Solution {
public:
    int numberOfMatches(int n) {
        int matches = 0, teams = 0;
        while(n > 1) {
            if(n % 2 == 0) {
                matches += n/2;
                n = n/2;
                // cout << "matches1 = " << matches << " n1= " << n << endl;
            }
            else {
                matches += (n-1)/2;
                n = ((n-1)/2)+1;
                // cout << "matches2 = " << matches << " n2= " << n << endl;
            }
        }
        return matches; 
    }
};