class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Conversions:
        // vector<int> row(n, 0);   --> matrix[..][0]
        // vector<int> col(m, 0);   --> matrix[0][..]

        int col0 = 1;
        // Iterating and marking row and column vector elements as 0s
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    // marking the ith row element as 0
                    matrix[i][0] = 0;
                    // marking the jth column element as 0 if it is not first element
                    // otherwise marking col0 as 0
                    if(j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }

        // Iterating and marking remaining elements as 0s
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] != 0) {
                    // Checking in row and column vectors for 0s
                    if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        // If matrix[0][0] is 0, then all the column vector elements are 0s 
        // (Need to mark for column vector elements first before row vector elements)
        if(matrix[0][0] == 0) {
            for(int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // If col0 is 0, then all the row vector elements are 0s
        if(col0 == 0) {
            for(int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }


    }
};