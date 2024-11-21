class Solution {
public:    
    void markCellAsGuarded(int row, int col, vector<vector<int>>& grid) {
        
        // UP DIRECTION
        // Marking cells in up direction from current cell as guarded
        for(int i = row-1; i >= 0; i--) {
            if(grid[i][col] == 1 || grid[i][col] == -1) {
                break;
            }
            grid[i][col] = 2;
        }
        
        // DOWN DIRECTION
        // Marking cells in down direction from current cell as guarded
        for(int i = row+1; i < grid.size(); i++) {
            if(grid[i][col] == 1 || grid[i][col] == -1) {
                break;
            }
            grid[i][col] = 2;
        }
        
        // LEFT DIRECTION
        // Marking cells in left direction from current cell as guarded
        for(int j = col-1; j >= 0; j--) {
            if(grid[row][j] == 1 || grid[row][j] == -1) {
                break;
            }
            grid[row][j] = 2;
        }
        
        // RIGHT DIRECTION
        // Marking cells in right direction from current cell as guarded
        for(int j = col+1; j < grid[0].size(); j++) {
            if(grid[row][j] == 1 || grid[row][j] == -1) {
                break;
            }
            grid[row][j] = 2;
        }
    }
    
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int> (n, 0));
        
        for(auto &guard: guards) {
            int i = guard[0];
            int j = guard[1];
            grid[i][j] = 1;
        }
        
        for(auto &wall: walls) {
            int i = wall[0];
            int j = wall[1];
            grid[i][j] = -1;
        }
        
        for(auto &guard: guards) {
            int i = guard[0];
            int j = guard[1];
            markCellAsGuarded(i, j, grid);
        }
        
        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0)
                    count++;
            }
        }
        
        return count;
    }
};