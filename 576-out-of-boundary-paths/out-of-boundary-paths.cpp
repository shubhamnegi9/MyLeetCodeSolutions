class Solution {
public:
    int MOD = 1e9+7;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int dp[51][51][51]; // Since the constraints for m, n and maxMove are less, so we can create array. Otherwise map need to be created for large constraints

    // Using Recursion
    // T.C. = O(4^(maxMove)), S.C. = O(maxMoves)
    int solve(int m, int n, int maxMove, int startRow, int startColumn) {
        // Base Case
        // Goes out of grid boundary
        if(startRow < 0 || startRow >= m || startColumn < 0 || startColumn >= n)
            return 1;
        
        // If no more moves left
        if(maxMove <= 0)
            return 0;
        
        int res = 0;
        for(auto dir: directions) {
            res = (res + solve(m, n, maxMove-1, startRow+dir[0], startColumn+dir[1]))%MOD;
        }
        return res;
    }

    // Using Top Down Approach (Recursion + Memoization)
    // T.C. = O(m*n*maxMove), S.C. = O(m*n*maxMove)
    int solveMemo(int m, int n, int maxMove, int startRow, int startColumn) {
        // Base Case
        // Goes out of grid boundary
        if(startRow < 0 || startRow >= m || startColumn < 0 || startColumn >= n)
            return 1;
        
        // Contains in dp table
        if(dp[startRow][startColumn][maxMove] != -1) {
            return dp[startRow][startColumn][maxMove];
        }

        // If no more moves left
        if(maxMove <= 0)
            return 0;
        
        int res = 0;
        for(auto dir: directions) {
            res = (res + solveMemo(m, n, maxMove-1, startRow+dir[0], startColumn+dir[1]))%MOD;
        }

        // Storing in dp table before returning
        return dp[startRow][startColumn][maxMove] = res;
    }
    
    // Using Bottom Up Approach
    // T.C. = O(m*n*maxMove), S.C. = O(m*n*maxMove)
    int solveBottomUp(int m, int n, int maxMove, int startRow, int startColumn) {
        int t[m][n][maxMove+1];
        memset(t, 0, sizeof(t));

        // t[i][j][k] represents number of possible paths out of grid when you are standing at [i][j] and you have k moves at max

        for(int k = 1; k <= maxMove; k++) {
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    for(vector<int> &dir: directions) {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if(x < 0 || x >= m || y < 0 || y >= n) {
                            t[i][j][k] = (t[i][j][k] + 1) % MOD;
                        }
                        else {
                            t[i][j][k] = (t[i][j][k] + t[x][y][k-1]) % MOD;
                        }
                    }
                }
            }
        }

        return t[startRow][startColumn][maxMove];
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // Using Recursion/DFS
        // return solve(m, n, maxMove, startRow, startColumn);

        // Using Top Down Approach (Recursion + Memoization)
        // memset(dp, -1, sizeof(dp));
        // return solveMemo(m, n, maxMove, startRow, startColumn);

        // Using Bottom Up Approach
        return solveBottomUp(m, n, maxMove, startRow, startColumn);
    }   
};