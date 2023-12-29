class Solution {
public:
    // Since 2 variables 'index' and 'd' are changing
    // so taken 2D dp array
    // int dp[301][11];

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
            int ans = maxD + solve(jd, n, i+1, d-1);
            res = min(res, ans);
        }

        return res;
    }


    int dp[301][11];
    int solveMem(vector<int>& jobDifficulty, int n, int idx, int d) {
        
        // If you have only 1 day, then you will do all the remaining jobs
        // and select the max difficulty as the answer
        if (d == 1) {
            return *max_element(begin(jobDifficulty) + idx, end(jobDifficulty));
        }
        
        if (dp[idx][d] != -1)
            return dp[idx][d];
    
        int Max = INT_MIN;
        int result = INT_MAX;
        
        // Try one by one with all possibilities
        /*
            Take 1 job in one day
            Take 2 jobs in one day
            Take 3 jobs in one day
            and so on
            
            Then find the optimal one among all the results
        */
        for (int i = idx; i <= n - d; i++) {
            Max = max(Max, jobDifficulty[i]);
            result = min(result, Max + solveMem(jobDifficulty, n, i + 1, d - 1));
        }
        
        return dp[idx][d] = result;
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
        memset(dp, -1, sizeof(dp));
        return solveMem(jobDifficulty, n, 0, d);

    }
};