class Solution {
public:
    int m;
    int n;
    
    // Brute Force Approach using 2D matrix traversal
    int countSquares1(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int count = 0;
        
        // For size 1 submatrix
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1)
                    count++;
            }
        }
        
        // For size 2 and more submatrix
        for(int s = 2; s <= min(m, n); s++) {
            for(int i = 0; i < m-(s-1); i++) {
                for(int j = 0; j < n-(s-1); j++) {
                    int allOnes = true;
                    for(int k = i; k < i+s; k++) {
                        for(int l = j; l < j+s; l++) {
                            if(matrix[k][l] == 0) {
                                allOnes = false;
                                break;
                            }
                        }
                    }
                    if(allOnes)
                        count++;
                }
            }
        }
        
        return count;
    }
    
    // Better Approach using Recursion
    int solve(int i, int j, vector<vector<int>>& matrix) {
        
        if(i >= m || j >= n) {
            return 0;
        }
        
        if(matrix[i][j] == 0)
            return 0;
        
        int rightOnes   = solve(i, j+1, matrix);
        int diagOnes    = solve(i+1, j+1, matrix);
        int bottomOnes  = solve(i+1, j, matrix);
        
        return 1 + min({rightOnes, diagOnes, bottomOnes});
    }
    
    int countSquares2(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int count = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1) {
                    count += solve(i, j, matrix);
                }
            }
        }
        
        return count;
    }
    
     // Optimal Approach using Top Down DP (Memoization)
    int solveMemo(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        
        if(i >= m || j >= n) {
            return 0;
        }
        
        if(matrix[i][j] == 0)
            return 0;
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int rightOnes   = solveMemo(i, j+1, matrix, dp);
        int diagOnes    = solveMemo(i+1, j+1, matrix, dp);
        int bottomOnes  = solveMemo(i+1, j, matrix, dp);
        
        return dp[i][j] = 1 + min({rightOnes, diagOnes, bottomOnes});
    }
    
    int countSquares3(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int count = 0;
        
        vector<vector<int>> dp(m, vector<int> (n, -1));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1) {
                    count += solveMemo(i, j, matrix, dp);
                }
            }
        }
        
        return count;
    }
    
    int countSquares(vector<vector<int>>& matrix) {
        // Brute Force Approach
        // return countSquares1(matrix);
        
        // Better Approach using Recursion
        // return countSquares2(matrix);
        
        // Optimal Approach using Top Down DP (Memoization)
        return countSquares3(matrix);
    }
};