class Solution {
public:
    // Aprroach 1
    vector<vector<int>> construct2DArray1(vector<int>& original, int m, int n) {
        vector<vector<int>> result(m, vector<int>(n, 0));
        int l = original.size();
        // Corner case
        if(m*n != l) {
            return {};
        }
        
        int idx = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                result[i][j] = original[idx];
                idx++;
            }
        }
        return result;
    }
    
    // Aprroach 2
    vector<vector<int>> construct2DArray2(vector<int>& original, int m, int n) {
        vector<vector<int>> result(m, vector<int>(n, 0));
        int l = original.size();
        // Corner case
        if(m*n != l) {
            return {};
        }
        
        for(int i = 0; i < l; i++) {
            int row = i/n;
            int col = i%n;
            result[row][col] = original[i];
        }
        return result;
    }
    
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Aprroach 1
        // return construct2DArray1(original, m, n);
        
        // Aprroach 2
        return construct2DArray2(original, m, n);
    }
};