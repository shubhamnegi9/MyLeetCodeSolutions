class Solution {
public:
    
    void DFS(vector<vector<int>>& land, int i, int j, int m, int n, int &r2, int &c2) { // Passed r2 and c2 by reference 
        
        // Boundary conditions
        if(i < 0 || i >= m || j < 0 || j >= n || land[i][j] == 0)
            return;
        
        // Marking current cell as visited 
        land[i][j] = 0;

        // Finding max values of r2 and c2 which will be bottom right coordinates of this group
        r2 = max(r2, i);
        c2 = max(c2, j);

        // DFS traversal to top, left, bottom, right cells
        DFS(land, i+1, j, m, n, r2, c2);
        DFS(land, i, j+1, m, n, r2, c2);
        DFS(land, i-1, j, m, n, r2, c2);
        DFS(land, i, j-1, m, n, r2, c2);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> result;

        // Using DFS
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // Group found
                if(land[i][j] == 1) {
                    // Current i and j will be top left coordinates of group
                    // Intializing bottom right coordinates as -1 (as we need to find max)
                    int r1 = i, c1 = j, r2 = -1, c2 = -1;
                    // Finding bottom right coordinates of group using DFS
                    DFS(land, i, j, m, n, r2, c2);
                    result.push_back({r1, c1, r2, c2});
                }
            }
        }

        return result;
    }
};