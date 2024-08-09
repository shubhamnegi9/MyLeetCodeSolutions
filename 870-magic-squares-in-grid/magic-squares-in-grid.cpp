class Solution {
public:
    
    bool isMagicSquare(vector<vector<int>>& grid, int r, int c) {
        
        // Checking for digits 1 to 9 and unique digits in 3X3 subgrid
        unordered_set<int> st;  // Taking set to check for unique digits
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                int num = grid[r+i][c+j];
                // If number is less than 1 or more than 9 or contains in set then it is not magic square
                if(num < 1 || num > 9 || st.count(num)) {
                    return false;
                }
                else {
                    st.insert(num);
                }
            }
        }
        
        // Checking for equivalence of row sum, column sum, and both diagonal sum
        int SUM = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        
    
        for(int i = 0; i < 3; i++) {
            // Checking along the row
            if(grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != SUM) {
                return false;
            }
            // Checking along the column
            if(grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i] != SUM) {
                return false;
            }
        }
        
        // Checking along diagonal
        if(grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != SUM) {
            return false;
        }
        
        // Checking along anti-diagonal
        if(grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != SUM) {
            return false;
        }
        
        // If none of the above conditions matches, then it is magic box
        return true;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int count = 0;
        for(int i = 0; i <= rows-3; i++) {
            for(int j = 0; j <= cols-3; j++) {
                if(isMagicSquare(grid, i, j)) {
                    count++;
                }
            }
        }
        
        return count;
    }
};