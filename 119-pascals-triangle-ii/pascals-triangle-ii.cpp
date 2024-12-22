class Solution {
public:
    
    int findnCr(int n, int r) {
        long long res = 1;
        
        for(int i = 0; i < r; i++) {
            res = (long long) res * (n-i);
            res /= (i+1);
        }
        
        return (int) res;
    }
    
    // Brute Force Approach
    // T.C. = O(rowIndex*rowIndex)
    // S.C. = O(1) extra space
    vector<int> getRow1(int rowIndex) {
        vector<int> result(rowIndex+1);
        
        for(int c = 1; c <= rowIndex+1; c++) {
            result[c-1] = findnCr(rowIndex, c-1);
        }
        
        return result;
    }
    
    vector<int> getRow(int rowIndex) {
        // Brute Force Approach
        return getRow1(rowIndex);
    }
};