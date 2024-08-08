class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        // Vector for directions. Initially move east, then south, then west and finally north. After that it repeats.
        vector<vector<int>> directions = {
                                            {0, 1},     // EAST
                                            {1, 0},     // SOUTH
                                            {0, -1},    // WEST
                                            {-1, 0},    // NORTH      
                                        };
        
        vector<vector<int>> result;
        // Push starting cell row and column index in result vector
        result.push_back({rStart, cStart});
        
        int steps = 0;  // Number of steps in 'dir' direction
        int dir = 0;    // Represents index in 'directions' vector. Initially we will move east so dir = 0
        
        
        while(result.size() < rows * cols) {   // Traverse until all cells are in result vector
            
            // Whenever we move towards east or west, then steps increase by one
            if(dir == 0 || dir == 2) {
                steps++;
            }
            
            for(int i = 0; i < steps; i++) {
                // Finding new cell's index in 'dir' direction
                rStart += directions[dir][0];
                cStart += directions[dir][1];
                
                // Checking if the cell is within the boundary of grid. Then only push it into result vector
                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                    result.push_back({rStart, cStart});
                }
            }
            
            // Once the steps are completed in 'dir' direction, moving to new direction in cyclic way
            dir = (dir+1)%4;
            
        }
        
        return result;
        
    }
};