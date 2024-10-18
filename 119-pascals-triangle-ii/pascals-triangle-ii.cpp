class Solution {
public:
    // Approach 1: By creating whole Pascal Triangle and returning last row
    vector<int> getRow1(int rowIndex) {
        int numRows = rowIndex+1;
        vector<vector<int>> result(numRows);
        
        for(int i = 0; i < numRows; i++) {
            result[i] = vector<int>(i+1, 1);
            
            for(int j = 1; j < i; j++) {
                result[i][j] = result[i-1][j] + result[i-1][j-1];
            } 
        }
        
        return result[rowIndex];
    }
    
    // Approach 2: Space Optimized Approach
    vector<int> getRow2(int rowIndex) {
        vector<int> prev;
        
        for(int i = 0; i < rowIndex+1; i++) {
            vector<int> curr(i+1, 1);
            
            for(int j = 1; j < i; j++) {
                curr[j] = prev[j] + prev[j-1];
            } 
            
            prev = curr;
        }
        
        return prev;
    
    }
    vector<int> getRow(int rowIndex) {
        // Approach 1
        // return getRow1(rowIndex);
        
        
        // Approach 2
        return getRow2(rowIndex);
    }
};