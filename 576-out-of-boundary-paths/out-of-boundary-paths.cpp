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
    int solveMemo(int m, int n, int maxMove, int startRow, int startColumn) {
        // Base Case
        // Goes out of grid boundary
        if(startRow < 0 || startRow >= m || startColumn < 0 || startColumn >= n)
            return 1;
        
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
        return dp[startRow][startColumn][maxMove] = res;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // Using Recursion/DFS
        // return solve(m, n, maxMove, startRow, startColumn);

        // Using Top Down Approach (Recursion + Memoization)
        memset(dp, -1, sizeof(dp));
        return solveMemo(m, n, maxMove, startRow, startColumn);
    }   
};