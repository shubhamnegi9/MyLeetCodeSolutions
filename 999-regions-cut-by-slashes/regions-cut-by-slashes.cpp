class Solution {
public:
    
    void numberOfRegionsUsingDFS(vector<vector<int>> &matrix, int i, int j) {
        int m = matrix.size();
        int n = matrix[0].size();
        // Return for boundary conditions and visited cells
        if(i < 0 || i >= m || j < 0 || j >=n || matrix[i][j] == 1) {
            return;
        }
        
        matrix[i][j] = 1; // Mark cell as visited 
        // DFS for neghbouring cells
        numberOfRegionsUsingDFS(matrix, i, j+1);
        numberOfRegionsUsingDFS(matrix, i+1, j);
        numberOfRegionsUsingDFS(matrix, i, j-1);
        numberOfRegionsUsingDFS(matrix, i-1, j);
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int regions = 0;
        // Initializing a matrix where each symbol from given grid is represented as 3X3 subgrid in matrix
        // Size of this matrix will be (rows*3) X (cols*3). Initially it contains all 0s
        vector<vector<int>> matrix(rows*3, vector<int>(cols*3, 0));
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == '/') {
                    // Making anti-diagonal elements in corres. subgrid as 1s
                    matrix[i*3][j*3+2] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3] = 1;
                }
                else if(grid[i][j] == '\\') {
                    // Making diagonal elements in corres. subgrid as 1s
                    matrix[i*3][j*3] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3+2] = 1;
                }
            }
        }
        
        // Using 'Number of Islands' problem approach to find regions
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0l; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    // Calling DFS for all the neighbouring 0s and increasing number of region once for them
                    numberOfRegionsUsingDFS(matrix, i, j);   
                    regions++;
                }
            }
        }
        
        return regions;
    }
};