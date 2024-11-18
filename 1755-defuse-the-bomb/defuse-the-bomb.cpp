class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        
        if(k == 0) {
            return result;
        }
        
        if(k > 0) {
            for(int i = 0; i < n; i++) {
                int idx = (i+1)%n;
                int sum = 0;
                for(int j = 0; j < k; j++) {
                    sum += code[idx];
                    idx = (idx+1)%n;
                }
                result[i] = sum;
            }
        }
        else {
            for(int i = 0; i < n; i++) {
                int idx = (i-1+n)%n;
                int sum = 0;
                for(int j = 0; j < abs(k); j++) {
                    sum += code[idx];
                    idx = (idx-1+n)%n;
                }
                result[i] = sum;
            }
        }
        
        return result;
    }
};