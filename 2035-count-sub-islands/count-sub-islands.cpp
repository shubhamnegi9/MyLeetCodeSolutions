class Solution {
public:
    
    bool isSubIslandDFS(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        
        /*
            When you hit a cell != 1, it means that while traversing the Island, you have hit a point where it’s water.             This doesn’t violate the requirement of the problem. So we return true.
            We can only return false when a cell is land in grid2 but it’s not a land in grid1
        */
        if(i < 0 || i >= grid2.size() || j < 0 || j >= grid2[0].size() || grid2[i][j] != 1) {
            return true;
        }
        
        grid2[i][j] = -1;   //mark visited
        
        bool result = (grid1[i][j] == 1);
        
        result = result & isSubIslandDFS(grid1, grid2, i+1, j);
        result = result & isSubIslandDFS(grid1, grid2, i, j+1);
        result = result & isSubIslandDFS(grid1, grid2, i-1, j);
        result = result & isSubIslandDFS(grid1, grid2, i, j-1);
        
        return result;
    } 
    
    //BFS
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; //down, up, right , left
    bool isSubIslandBFS(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        int m = grid1.size();
        int n = grid1[0].size();

        bool result = true;

        queue<pair<int, int>> que; //{i, j} //BFS me we use queue
        que.push({i, j});
        grid2[i][j] = -1; //mark visited

        while(!que.empty()) {
            auto [x, y] = que.front();
            que.pop();

            if(grid1[x][y] != 1) { //grid1 must have 1 at that same co-ordinate
                result = false;
            }

            for(vector<int>& dir : directions) {
                int newX = x + dir[0];
                int newY = y + dir[1];

                if(newX >= 0 && newX < m && newY >= 0 && newY < n && grid2[newX][newY] == 1) {
                    grid2[newX][newY] = -1; //mark visited
                    que.push({newX, newY});
                }
            }
        }

        return result;
    }
        
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size();
        
        int subIslands = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1 && isSubIslandBFS(grid1, grid2, i, j)) {
                    subIslands++;
                }
            }
        }
        
        return subIslands;
    }
};