class Solution {
public:
    // Rotate the matrix clockwise by 90 degrees
    vector<vector<int>> rotateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        
        // Find transpose of matrix
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        
        // Reverse each row of matrix
        for(vector<int> &row: mat) {
            reverse(row.begin(), row.end());
        }
        
        return mat;
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        
        for(int i = 0; i < 4; i++) {
            if(rotateMatrix(mat) == target) {
                return true;
            }
        }
        
        return false;
    }
};