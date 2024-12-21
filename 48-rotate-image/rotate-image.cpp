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
    
    void rotate(vector<vector<int>>& matrix) {
        // Brute Force Approach
        return rotate1(matrix);
        
        // // Optimal Approach
        // return rotate2(matrix);
    }
};