class Solution {
public:
    int m, n;

    // Recursive Approach
    int solve(int i, int j, vector<vector<char>>& matrix) {
        
        if(i >= m || j >= n)
            return 0;
        
        if(matrix[i][j] == '0')
            return 0;
        
        int rightOnes   = solve(i, j+1, matrix);
        int diagOnes    = solve(i+1, j+1, matrix);
        int bottomOnes  = solve(i+1, j, matrix);
        
        return 1 + min({rightOnes, diagOnes, bottomOnes}); 
    }
    
    int maximalSquare1(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int maxSide = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') {
                    int side = solve(i, j, matrix);
                    maxSide = max(maxSide, side);
                }
            }
        }
        
        return maxSide*maxSide;
    }
    
    // Top Down Memoization
    int solveMemo(int i, int j, vector<vector<char>>& matrix, vector<vector<int>> &dp) {
        
        if(i >= m || j >= n)
            return 0;
        
        if(matrix[i][j] == '0')
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int rightOnes   = solveMemo(i, j+1, matrix, dp);
        int diagOnes    = solveMemo(i+1, j+1, matrix, dp);
        int bottomOnes  = solveMemo(i+1, j, matrix, dp);
        
        return dp[i][j] = 1 + min({rightOnes, diagOnes, bottomOnes}); 
    }
    
    int maximalSquare2(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int maxSide = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') {
                    int side = solveMemo(i, j, matrix, dp);
                    maxSide = max(maxSide, side);
                }
            }
        }
        
        return maxSide*maxSide;
    }
    
    // Bottom Up Approach
    int maximalSquare3(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int maxSide = 0;
        
        vector<vector<int>> t(m, vector<int>(n, 0));
        
        // t[i][j] = total square submmatrix having all 1s and ending at cell [i][j]
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0) {
                    t[i][j] = (matrix[i][j] - '0');
                }
                else if(matrix[i][j] == '1') {
                    t[i][j] = 1+ min({t[i-1][j], t[i-1][j-1], t[i][j-1]});
                }
                maxSide = max(maxSide, t[i][j]);
            }
        }
        
        return maxSide*maxSide;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        
        // Recursive Approach
        // return maximalSquare1(matrix);
        
        // Top Down Memoization
        // return maximalSquare2(matrix);
        
        // Bottom Up Approach
        return maximalSquare3(matrix);
    }
};