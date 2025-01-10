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
    
    void setZeroes(vector<vector<int>>& matrix) {
        // Brute Force Approach using extra space
        return setZeroes1(matrix);   
    }
};