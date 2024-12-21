class Solution {
public:
    
    // Brute Force Approach with extra space
    // T.C. = O(m*n)*O(m+n)
    // S.C. = O(m*n)
    void setZeroes1(vector<vector<int>>& matrix) {
        vector<vector<int>> temp(matrix);
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
    // (Can be used if matrix contains positive elements only, since -1 will conflict with the matrix values)
    // T.C. = O(m*n)*O(m+n) + O(m*n)
    // S.C. = O(1)
    void setZeroes2(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    for(int k = 0; k < m; k++) {
                        if(matrix[k][j] != 0)
                            matrix[k][j] = -1;
                    }
                    for(int k = 0; k < n; k++) {
                        if(matrix[i][k] != 0)
                           matrix[i][k] = -1;
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
    
    // Better Approach using row and col vectors
    // T.C. = 2 * O(m*n)
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
    
    void setZeroes4(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int col0 = 1;
        
        // Filling row vector (matrix[i][0]) and column vector (matrix[0][j], col0) with 0s
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    // Filling row vector
                    matrix[i][0] = 0;
                    
                    // Filling column vector
                    if(j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }
        
        // Setting remaining elements to 0s based on row and column vector values
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        
        // Setting column vector values to 0s first based on matrix[0][0]
        if(matrix[0][0] == 0) {
            for(int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        
        // Setting row vector values to 0s then based on col0
        if(col0 == 0) {
            for(int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        // Brute Force Approach with extra space
        // return setZeroes1(matrix);
        
        // Brute Force Approach without extra space
        // return setZeroes2(matrix);
        
        // Better Approach using row and col vectors
        // return setZeroes3(matrix);
        
        // Optimal Approach
        return setZeroes4(matrix);
    }
};