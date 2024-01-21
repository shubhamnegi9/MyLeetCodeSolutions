class Solution {
public:
    // Since 2 variables 'index' and 'd' are changing
    // so taken 2D dp array
    int dp[301][11];

    // Recursive Way
    int solve(vector<int> jd, int n, int index, int d) {
        /*
            Base Case:
            If there is only 1 day left, 
            then we need to complete all the remaining 
            jobs in that one day and find the maximum
            difficulty for that day
        */
        if(d == 1) {
            int maxD = jd[index];
            // Iterating in all the remaining jobs
            // and finding the maximum difficulty job
            for(int i = index; i < n; i++) {
                maxD = max(maxD, jd[i]);
            }

            // Return this maximum difficulty job
            return maxD;
        }

        int maxD = jd[index];
        int res = INT_MAX;

        /*
            One by one trying every possibility
            and finding optimal minimum difficulty:
            Doing only 1 job J1 at {index} on first day and finding difficulty
            Doing 2 jobs {J1, J2} at {index, index+1} on first day and finding difficulty
            ...
            Finally finding minimum of all difficulties
        */
        /* Iterating only till (n-d) jobs because
            if we iterate more than (n-d) jobs
            then for remaining days there will
            no job left to do
        */
        for(int i = index; i <= n-d; i++) {
            maxD = max(maxD, jd[i]);
            // Finding difficulty for remaining days 
            // using recursion and adding them to 
            // current day difficulty
            int ans = maxD + solve(jd, n, i+1, d-1);
            // finding minimum of all difficulties
            res = min(res, ans);
        }

        return res;
    }


    // Recursive + Memoization
    // or Top Down Approach
    int solveMem(vector<int> &jd, int n, int index, int d) {
        /*
            Base Case:
            If there is only 1 day left, 
            then we need to complete all the remaining 
            jobs in that one day and find the maximum
            difficulty for that day
        */
        if(d == 1) {
            int maxD = INT_MIN;
            // Iterating in all the remaining jobs
            // and finding the maximum difficulty job
            for(int i = index; i < n; i++) {
                maxD = max(maxD, jd[i]);
            }

            // Return this maximum difficulty job
            return maxD;
        }

        // If result present in dp array
        // then return from it
        if(dp[index][d] != -1) {
            return dp[index][d];
        }

        int maxD = INT_MIN;
        int res = INT_MAX;

        /*
            One by one trying every possibility
            and finding optimal minimum difficulty:
            Doing only 1 job J1 at {index} on first day and finding difficulty
            Doing 2 jobs {J1, J2} at {index, index+1} on first day and finding difficulty
            ...
            Finally finding minimum of all difficulties
        */
        /* Iterating only till (n-d) jobs because
            if we iterate more than (n-d) jobs
            then for remaining days there will
            no job left to do
        */
        for(int i = index; i <= n-d; i++) {
            maxD = max(maxD, jd[i]);
            int ans = maxD + solveMem(jd, n, i+1, d-1);
            res = min(res, ans);
        }

        // Storing result in dp array and returned it
        return dp[index][d] = res;
    }

    // Using Bottom Up Approach
    int solveBottomUp(vector<int> &jd, int n, int d, vector<vector<int>> &t) {

        // t[i][j] = Minimum difficulty of doing job from index i to index n-1 in d days
        
        /*
            Base Case:
            If there is only 1 day left, 
            then we need to complete all the remaining 
            jobs in that one day and find the maximum
            difficulty for that day
        */
        for(int i = 0; i < n; i++) {
            t[i][1] = *max_element(jd.begin()+i, jd.end());
        }

        for(int days = 2; days <= d; days++) {
            for(int i = 0; i <= n-days; i++) {
                int maxD = INT_MIN;
                int res = INT_MAX;
                for(int j = i; j <= n-days; j++) {
                    maxD = max(maxD, jd[j]);
                    int ans = maxD + t[j+1][days-1];
                    res = min(res, ans);
                }

                t[i][days] = res;
            }
        }

        // Minimum difficulty of doing job from index 0 to index n-1 in d days
        return t[0][d];
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        /* 
            If number of days are more than size
            of the array, then jobs cannot be 
            scheduled because there will be 
            empty days even if we schedule one job
            per day
            Eg. jobDifficulty = [9,9,9], d = 4
        */
        if(n < d) {
            return -1;
        }

        // Recursive Way
        // return solve(jobDifficulty, n, 0, d);

        // Recursive + Memoization
        // memset(dp, -1, sizeof(dp));
        // return solveMem(jobDifficulty, n, 0, d);

        // Bottom Up Approach
        vector<vector<int>> t(n, vector<int>(d+1, -1));
        return solveBottomUp(jobDifficulty, n, d, t);
    }
};