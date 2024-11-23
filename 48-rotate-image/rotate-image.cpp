class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Finding transpose of matrix
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {    // Start j from i and not from 0 
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
        
        // Reverse each row of transpose matrix
        // Used row as reference (&) as we need to make the changes of each row in matrix also
        for(vector<int>& row: matrix) {
            reverse(row.begin(), row.end());
        }
    }
};