class Solution {
public:

    // Using DFS
    void DFS(vector<vector<int>>& grid, int i, int j, int m, int n, int &peri) {
        
        // In case of going out of grid boundary or going to water cell,
        // increase the perimeter by 1 as there would be wall in between
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            peri++;
            return;
        }

        // Return from already visited cell
        if(grid[i][j] == -1)
            return;
        
        // Mark current cell as visited
        // If we don't mark it as visited then we will stuck in infinite loop during traversal
        grid[i][j] = -1;

        // Calling DFS for adjacent cells
        DFS(grid, i+1, j, m, n, peri);
        DFS(grid, i, j+1, m, n, peri);
        DFS(grid, i-1, j, m, n, peri);
        DFS(grid, i, j-1, m, n, peri);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();        // Rows
        int n = grid[0].size();     // Columns
        int perimeter = 0;

        // Using DFS
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // Start DFS from the cell containing 1
                if(grid[i][j] == 1) {
                    DFS(grid, i, j, m, n, perimeter);
                }
            }
        }

        return perimeter;
    }
};