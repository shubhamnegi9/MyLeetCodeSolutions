class Solution {
public:
    
    int findnCr(int n, int r) {
        long long res = 1;
        
        for(int i = 0; i < r; i++) {
            res = (long long) res * (n-i);  // Handle signed int overflow
            res /= (i+1);
        }
        
        return (int) res;
    }
    
    // Brute Force Approach 1
    // T.C. = O(rowIndex*rowIndex)
    // S.C. = O(1) extra space
    vector<int> getRow1(int rowIndex) {
        vector<int> result(rowIndex+1);
        
        for(int c = 1; c <= rowIndex+1; c++) {
            result[c-1] = findnCr(rowIndex, c-1);
        }
        
        return result;
    }
    
    // Brute Force Approach 2
    // T.C. = O(rowIndex*rowIndex)
    // S.C. = O(rowIndex*rowIndex) extra space
    vector<int> getRow2(int rowIndex) {
        vector<vector<int>> result(rowIndex+1);
            
        for(int i = 0; i < rowIndex+1; i++) {
            result[i] = vector<int> (i+1, 1);
            for(int j = 1; j < i; j++) {
                result[i][j] = result[i-1][j] + result[i-1][j-1]; 
            }
        }
        
        return result[rowIndex];
    }
    
    // Better Approach space-wise
    // T.C. = O(rowIndex*rowIndex)
    // S.C. = O(1) extra space
    vector<int> getRow3(int rowIndex) {
        vector<int> prev;
        vector<int> curr(rowIndex+1, 1);
        for(int i = 0; i < rowIndex+1; i++) {
            for(int j = 1; j < i; j++) {
                curr[j] = prev[j] + prev[j-1]; 
            }
            prev = curr;
        }
        
        return curr;
    }
    
    // Optimal Approach
    // T.C. = O(rowIndex)
    // S.C. = O(1) extra space
    vector<int> getRow4(int rowIndex) {
        int n = rowIndex+1;
        long long res = 1;
        vector<int> ans;
        ans.push_back((int) res);
        
        for(int i = 1; i < n; i++) {
            res = res * (n-i);
            res /= i;
            ans.push_back((int) res);
        }
        
        return ans;
    }
    
    vector<int> getRow(int rowIndex) {
        // Brute Force Approach 1
        // return getRow1(rowIndex);
        
        // Brute Force Approach 2
        // return getRow2(rowIndex);
        
        // Better Approach space-wise
        // return getRow3(rowIndex);
        
        // Optimal Approach
        return getRow4(rowIndex);
    }
};