class Solution {
public:
    
    bool isSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        
        if(i < 0 || i >= grid2.size() || j < 0 || j >= grid2[0].size() || grid2[i][j] != 1) {
            return true;
        }
        
        grid2[i][j] = -1;
        
        bool result = (grid1[i][j] == 1);
        
        result = result & (isSubIsland(grid1, grid2, i+1, j));
        result = result & (isSubIsland(grid1, grid2, i, j+1));
        result = result & (isSubIsland(grid1, grid2, i-1, j));
        result = result & (isSubIsland(grid1, grid2, i, j-1));
        
        return result;
    } 
        
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size();
        
        int subIslands = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1 && isSubIsland(grid1, grid2, i, j)) {
                    subIslands++;
                }
            }
        }
        
        return subIslands;
    }
};