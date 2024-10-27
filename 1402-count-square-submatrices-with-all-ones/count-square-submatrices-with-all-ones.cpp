class Solution {
public:
    int m;
    int n;
    
    // Brute Force Approach using 2D matrix traversal
    // T.C. = O(m×n×min(m,n)^2) 
    // S.C. = O(1)
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
    
    // Brute Force Approach using Recursion
    // T.C. = O(3^(m×n))
    // S.C. = O(max(m,n))
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
    //T.C : O(m*n)
    //S.C : O(m*n)
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
        
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1) {
                    count += solveMemo(i, j, matrix, dp);
                }
            }
        }
        
        return count;
    }
    
    // Optimal Approach using Bottom Up DP
    //T.C : O(m*n)
    //S.C : O(m*n)
    int countSquares4(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int count = 0;
        
        vector<vector<int>> t(m, vector<int>(n, 0));
        
        // t[i][j] = total square submmatrix having all 1s and ending at cell [i][j]
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0) {
                    t[i][j] = matrix[i][j];
                }
                else if(matrix[i][j] == 1) {
                    t[i][j] = 1+ min({t[i-1][j], t[i-1][j-1], t[i][j-1]});
                }
                count+=t[i][j];
            }
        }
        
        return count;
    }
    
    int countSquares(vector<vector<int>>& matrix) {
        // Brute Force Approach
        // return countSquares1(matrix);
        
        // Brute Force Approach using Recursion
        // return countSquares2(matrix);
        
        // Optimal Approach using Top Down DP (Memoization)
        // return countSquares3(matrix);
        
        // Optimal Approach using Bottom Up DP
        return countSquares4(matrix);
    }
};