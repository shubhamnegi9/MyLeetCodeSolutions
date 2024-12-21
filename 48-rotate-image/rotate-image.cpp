class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n*n)
    // S.C. = O(n*n)
    void rotate1(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> result(n, vector<int> (n, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                result[j][n-1-i] = matrix[i][j];
            }
        }
        
        matrix = result;
    }
    
    // Optimal Approach
    // T.C. = 2*O(n*n)
    // S.C. = O(1)
    void rotate2(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Finding transpose of matrix
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Reverse each row of matrix
        for(vector<int> &row: matrix) {
            reverse(row.begin(), row.end());
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        // Brute Force Approach
        // return rotate1(matrix);
        
        // Optimal Approach
        return rotate2(matrix);
    }
};