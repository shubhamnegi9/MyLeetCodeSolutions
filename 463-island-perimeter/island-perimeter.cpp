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
        
        // Mark current cell as visited using -1
        // If we don't mark it as visited then we will stuck in infinite loop during traversal
        grid[i][j] = -1;

        // Calling DFS for adjacent cells
        DFS(grid, i+1, j, m, n, peri);
        DFS(grid, i, j+1, m, n, peri);
        DFS(grid, i-1, j, m, n, peri);
        DFS(grid, i, j-1, m, n, peri);
    }

    void BFS(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>> directions, int &peri) {

        queue<pair<int, int>> q;
        // Pushing currrent cell position in queue
        q.push({i, j});
        // Marking current cell as visited using -1
        grid[i][j] = -1;

        while(!q.empty()) {
            // Taking out front element from queue and doing BFS on its neighbours
            auto it = q.front();
            q.pop();

            for(auto &dir: directions) {
                // Coordinates for adjacent cells
                int new_i = it.first + dir[0];
                int new_j = it.second + dir[1];

                // In case of going out of grid boundary or going to water cell,
                // increase the perimeter by 1 as there would be wall in between
                if(new_i < 0 || new_i >= m || new_j < 0 || new_j >= n || grid[new_i][new_j] == 0) {
                    peri++;
                    continue;
                }
                // Continue from already visited cell
                else if(grid[new_i][new_j] == -1) {
                    continue;
                }
                else {
                    // Marking adjacent cells as visited and pushing its position in queue
                    grid[new_i][new_j] = -1;
                    q.push({new_i, new_j});
                }
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();        // Rows
        int n = grid[0].size();     // Columns
        int perimeter = 0;

        // Using DFS
        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {
        //         // Start DFS from the cell containing 1
        //         if(grid[i][j] == 1) {
        //             DFS(grid, i, j, m, n, perimeter);
        //         }
        //     }
        // }

        // Using BFS
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // Start BFS from the cell containing 1
                if(grid[i][j] == 1) {
                    BFS(grid, i, j, m, n, directions, perimeter);
                }
            }
        }


        return perimeter;
    }
};