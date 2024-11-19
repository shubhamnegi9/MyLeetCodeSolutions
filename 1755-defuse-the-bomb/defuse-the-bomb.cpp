class Solution {
public:
    // Approach 1: Brute Force
    // T.C. = O(n*k)
    vector<int> decrypt1(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        
        if(k == 0) {
            return result;
        }
        
        if(k > 0) {
            for(int i = 0; i < n; i++) {        // O(n)
                int idx = (i+1)%n;              // If i = n-1, then idx = 0
                int sum = 0;
                for(int j = 0; j < k; j++) {    // O(k)
                    sum += code[idx];
                    idx = (idx+1)%n;            // Moving to right safely in rotated array
                }
                result[i] = sum;
            }
        }
        else {
            for(int i = 0; i < n; i++) {            // O(n)
                int idx = (i-1+n)%n;                // If i = 0, then idx = n-1
                int sum = 0;
                for(int j = 0; j < abs(k); j++) {   // O(k)
                    sum += code[idx];
                    idx = (idx-1+n)%n;              // Moving to left safely in rotated array
                }
                result[i] = sum;
            }
        }
        
        return result;
    }
    
    // Approach 2: Optimal Approach using Sliding Window
    // T.C. = O(n)
    vector<int> decrypt2(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        
        if(k == 0) {
            return result;
        }
        
        int i = -1, j = -1;

        if(k > 0) {
            // Starting window will be from {1, k}
            i = 1;
            j = k;
        } else {
            // Starting window will be from {n-|k|, n-1}
            i = n-abs(k);
            j = n-1;
        }
        
        int currWindowSum = 0;
        // Finding sum of starting window elements
        for(int cnt = i; cnt <= j; cnt++) {
            currWindowSum += code[cnt];
        }
        
        // Slide the window 'n' times and find the sum and store in result
        for(int l = 0; l < n; l++) {
            result[l] = currWindowSum;
            
            // Slide the window to right
            currWindowSum -= code[i];   // First remove element at 'i' from currWindowSum
            i = (i+1)%n;                // Move 'i' to right safely in rotated array
            
            j = (j+1)%n;                // First moving 'j' to right safely in rotated array
            currWindowSum += code[j];   // Add element at 'j' in currWindowSum
        }
        
        return result;
    }
    
    vector<int> decrypt(vector<int>& code, int k) {
        // Approach 1: Brute Force
        // return decrypt1(code, k);
        
        // Approach 2: Optimal Approach using Sliding Window
        return decrypt2(code, k);
    }
};