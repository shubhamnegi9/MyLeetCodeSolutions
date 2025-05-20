class Solution {
public:
    // Brute Force Approach (Will not work if matrix already contains -1)
    // T.C. = O(m*n)*O(m+n) + O(m*n)
    // S.C. = O(1)
    void setZeroes1(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    for(int k = 0; k < n; k++) {
                        if(matrix[i][k] != 0) 
                            matrix[i][k] = -1;
                    }
                    for(int k = 0; k < m; k++) {
                        if(matrix[k][j] != 0)
                            matrix[k][j] = -1;
                    }
                }
            }
        }    

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == -1)
                    matrix[i][j] = 0;
            }
        }
    }

    // Better Approach
    // T.C. = 2*O(m*n) 
    // S.C. = O(m+n)
    void setZeroes2(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    
    // Optimal Approach
    void setZeroes3(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        int col0 = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if(j != 0)  
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(matrix[0][0] == 0) {
            for(int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        if(col0 == 0) {
            for(int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }

    }

    void setZeroes(vector<vector<int>>& matrix) {
        // Brute Force Approach
        // setZeroes1(matrix);

        // Better Approach
        // setZeroes2(matrix);

        // Optimal Approach
        setZeroes3(matrix);
    }
};