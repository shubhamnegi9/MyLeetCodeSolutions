class Solution {
public:
    
    // Using DFS
    void DFS(vector<vector<int>>& land, int i, int j, int m, int n, int &r2, int &c2, vector<vector<int>> directions) { // Passed r2 and c2 by reference 
        
        // Boundary conditions
        if(i < 0 || i >= m || j < 0 || j >= n || land[i][j] == 0)
            return;
        
        // Marking current cell as visited 
        land[i][j] = 0;

        // Finding max values of r2 and c2 which will be bottom right coordinates of this group
        r2 = max(r2, i);
        c2 = max(c2, j);

        // DFS traversal to top, left, bottom, right cells
        for(auto dir: directions) {
            DFS(land, i+dir[0], j+dir[1], m, n, r2, c2, directions);
        }
    }

    // Using BFS
    void BFS(vector<vector<int>>& land, int i, int j, int m, int n, int &r2, int &c2, vector<vector<int>> directions) { // Passed r2 and c2 by reference 

        queue<pair<int, int>> q;
        // Pushing current coordinates to queue
        q.push({i, j});
        
        // Marking current cell as visited 
        land[i][j] = 0;

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            // Finding max values of r2 and c2 which will be bottom right coordinates of this group
            r2 = max(r2, it.first);
            c2 = max(c2, it.second);

            for(auto dir: directions) {
                
                int new_i = it.first + dir[0];
                int new_j = it.second + dir[1];

                // Boundary conditions
                if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && land[new_i][new_j] == 1) {
                    // Marking new cell as visited 
                    land[new_i][new_j] = 0;
                    q.push({new_i, new_j});
                }
            }
        }
    }

    // Using Iterative Approach (Without DFS and BFS)
    vector<vector<int>> findFarmlandIterative(vector<vector<int>>& land, int m, int n) {
        vector<vector<int>> result;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // Group found
                if(land[i][j] == 1) {
                    // Current i and j will be top left coordinates of group
                    // Intializing bottom right coordinates as i and j
                    int r1 = i, c1 = j, r2 = i, c2 = j;

                    // Finding bottom most row of current group
                    // Keep moving down until 1 is found
                    while(r2 < m && land[r2][j] == 1) {
                        r2++;
                    }
                    // Finding right most column of current group
                    // Keep moving right until 1 is found
                    while(c2 < n && land[i][c2] == 1) {
                        c2++;
                    }

                    // Once above while loop ends, r2 and c2 will be one more than actual r2 and c2 (Because of r2++ and c2++)
                    // In case r2 and c2 are 0s initially, then we need to keep as same
                    r2 = r2==0 ? r2 : r2-1;
                    c2 = c2==0 ? c2 : c2-1;
                    
                    result.push_back({r1, c1, r2, c2});

                    // Marking all the 1s in the group as visited, so we don't traverse them again
                    for(int k = r1; k <= r2; k++) {
                        for(int l = c1; l <= c2; l++) {
                            land[k][l] = 0;
                        }
                    }
                }
            }
        }

        return result;
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> result;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Using DFS and BFS
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // Group found
                if(land[i][j] == 1) {
                    // Current i and j will be top left coordinates of group
                    // Intializing bottom right coordinates as -1 (as we need to find max)
                    int r1 = i, c1 = j, r2 = -1, c2 = -1;
                    
                    // Finding bottom right coordinates of group using DFS
                    // DFS(land, i, j, m, n, r2, c2, directions);

                    // Finding bottom right coordinates of group using BFS
                    // BFS(land, i, j, m, n, r2, c2, directions);

                    // result.push_back({r1, c1, r2, c2});
                }
            }
        }

        // Using Iterative Approach (Without DFS and BFS)
        result = findFarmlandIterative(land, m, n);

        return result;
    }
};