class Solution {
public:
    long long solve(vector<vector<int>>& questions, int n, int i) {
        // cout << "i= " << i << endl;
        if(i >= n) {
            return 0;
        }

        long long take = questions[i][0] + solve(questions, n, i+questions[i][1]+1);    // +1 to go after next i+questions[i][1] 
        long long skip = solve(questions, n, i+1);
        return max(take, skip);
    }

    long long solveMemo(vector<vector<int>>& questions, int n, int i, vector<long long>& dp) {
        // cout << "i= " << i << endl;
        if(i >= n) {
            return 0;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        long long take = questions[i][0] + solveMemo(questions, n, i+questions[i][1]+1, dp);
        long long skip = solveMemo(questions, n, i+1, dp);
        return dp[i] = max(take, skip);
    }


    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        // Using Recursion:
        // return solve(questions, n, 0);

        // Using Top-Down Memoization Approach:
        vector<long long> dp(n+1, -1);
        return solveMemo(questions, n, 0, dp);
    }
};