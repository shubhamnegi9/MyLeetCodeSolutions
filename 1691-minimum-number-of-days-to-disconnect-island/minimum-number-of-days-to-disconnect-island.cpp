class Solution {
public:
    int m, n;
    void DFS(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited) {
        
        // Return for out of boundary conditions or if cell is already visited or cell is water
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == 0)
            return;
        
        // Mark current cell as visited
        visited[i][j] = true;
        
        // Calling DFS on neighbours
        DFS(grid, i, j+1, visited);
        DFS(grid, i+1, j, visited);
        DFS(grid, i-1, j, visited);
        DFS(grid, i, j-1, visited);
    }
    
    int minNumOfIslandsUtil(vector<vector<int>>& grid) {
        
        
        // Visited array to keep track of the visited cells during DFS
        // (We cannot modify the cell during DFS as we need to do DFS many times here so we have taken visited array)
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        int islands = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // Calling DFS if the cell is land and not already visited
                if(grid[i][j] == 1 && !visited[i][j]) {
                    DFS(grid, i, j, visited);        
                    islands++;
                }
            }
        }
        
        return islands;
    }
    
    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int islands = 0;
        islands = minNumOfIslandsUtil(grid);
        
        // If number of islands are already 0 or more than 1, then it is already disconnected
        if(islands == 0 || islands > 1) {
            return 0;
        }
        else {
            // Numer of island is 1
            // Checking if we can disconnect the island in 1 day
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    // Making each land cell as water cell one by one and checking for island count
                    if(grid[i][j] == 1) {
                        grid[i][j] = 0;
                        islands = minNumOfIslandsUtil(grid);
                        if(islands == 0 || islands > 1) {
                            // we can disconnect the island in 1 day
                            return 1;
                        }
                        // Reseting the value of cell before moving to other cells
                        grid[i][j] = 1;   
                    }
                }
            }
        }
        // Island can be disconnected in 2 days
        return 2;
    }
};