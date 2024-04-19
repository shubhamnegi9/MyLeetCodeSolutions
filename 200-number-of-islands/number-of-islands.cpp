class Solution {
public:
    
    // Using DFS
    void DFS(vector<vector<char>>& grid, int i, int j, int m, int n) {

        // Boundary conditions (If 'i' and 'j' goes out of grid) 
        // and invalid coditions (If current cell element is '0' or '$') for DFS
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
            return;
        }

        // Marking current cell as visited using '$'
        grid[i][j] = '$';

        // Calling DFS for adjacent cells
        DFS(grid, i+1, j, m, n);
        DFS(grid, i-1, j, m, n);
        DFS(grid, i, j+1, m, n);
        DFS(grid, i, j-1, m, n);
    }

    // Using BFS
    void BFS(vector<vector<char>>& grid, int i, int j, int m, int n, vector<vector<int>> &directions) {
        
        queue<pair<int, int>> q;

        // Pushing currrent cell position in queue
        q.push({i, j});
        // Marking current cell as visited using '$'
        grid[i][j] = '$';

        while(!q.empty()) {

            // Taking out front element from queue and doing BFS on its neighbours
            auto it = q.front();
            q.pop();

            for(auto &dir: directions) {
                int new_i = it.first + dir[0];
                int new_j = it.second + dir[1];

                // Boundary conditions (If 'new_i' and 'new_j' goes out of grid) 
                // and invalid coditions (If current cell element is '0' or '$') for BFS
                if(new_i < 0 || new_i >= m || new_j < 0 || new_j >= n || grid[new_i][new_j] != '1') {
                    continue;
                }
                else {
                    // Marking adjacent cells as visited using '$' and pushing its position in queue
                    grid[new_i][new_j] = '$';
                    q.push({new_i, new_j});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();       // Rows
        int n = grid[0].size();    // Columns
        int islands = 0;

        // Using DFS
        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {
        //         if(grid[i][j] == '1') {
        //             DFS(grid, i, j, m, n);
        //                 // Increase islands count once DFS completes for current cell
        //             islands++;
        //         }
        //     }
        // }

        // Using BFS
        vector<vector<int>> directions = {{1, 0,}, {-1, 0}, {0, 1}, {0, -1}};
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    BFS(grid, i, j, m, n, directions);
                    // Increase islands count once DFS completes for current cell
                    islands++;
                }
            }
        }

        return islands;
    }
};