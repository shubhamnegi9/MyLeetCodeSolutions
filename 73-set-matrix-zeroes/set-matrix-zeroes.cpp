class Solution {
public:
    // Brute Force Approach using extra space
    // T.C. = O(m*n)*O(m+n)
    // S.C. = O(m*n)
    void setZeroes1(vector<vector<int>>& matrix) {
        vector<vector<int>> temp = matrix;
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    for(int k = 0; k < m; k++) {
                        temp[k][j] = 0;
                    }
                    for(int k = 0; k < n; k++) {
                        temp[i][k] = 0;
                    }
                }
            }
        }

        matrix = temp;
    }

    // Brute Force Approach without extra space
    // T.C. = O(m*n)*O(m+n) + O(m*n)
    // S.C. = O(1)
    void setZeroes2(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    for(int k = 0; k < m; k++) {
                        if(matrix[k][j] != 0) {
                            matrix[k][j] = -1;
                        }
                    }
                    for(int k = 0; k < n; k++) {
                        if(matrix[i][k] != 0) {
                            matrix[i][k] = -1;
                        }
                    }
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    
    // Better Approach
    // T.C. = 2*O(m*n)
    // S.C. = O(m+n)
    void setZeroes3(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

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
                if(row[i] == 1 || col[j] == 1)
                    matrix[i][j] = 0;
            }
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        // Brute Force Approach using extra space
        // return setZeroes1(matrix);   

        // Brute Force Approach without extra space
        // return setZeroes2(matrix);

        // Better Approach
        return setZeroes3(matrix);
    }
};