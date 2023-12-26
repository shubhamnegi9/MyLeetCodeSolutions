class Solution {
public:
    // Recursive Way
    int numRollsToTargetRecursive(int dices, int faces, int target) {
        
        // Base cases

        // If target is negative
        if(target < 0) 
            return 0;
        
        // If target is positive but no dices
        if(dices == 0 && target != 0) {
            return 0;
        }

        // If dices are present but target is 0
        if(dices != 0 && target == 0) {
            return 0;
        }

        // If no dice and target is also 0
        if(dices == 0 && target == 0) {
            return 1;
        }

        int ans = 0;
        // Iterating over each of the faces
        for(int i = 1; i <= faces; i++) {
            // For the next roll dice will decrease by 1 
            // and target will decrease by (target - current face value)
            ans += numRollsToTargetRecursive(dices-1, faces, target-i);
        }

        return ans;
    }

    // Using Memoization 
    long long numRollsToTargetHelper(int dices, int faces, int target, vector<vector<long long>>& dp) {
        
        // Base cases

        // If target is negative
        if(target < 0) 
            return 0;
        
        // If target is positive but no dices
        if(dices == 0 && target != 0) {
            return 0;
        }

        // If dices are present but target is 0
        if(dices != 0 && target == 0) {
            return 0;
        }

        // If no dice and target is also 0
        if(dices == 0 && target == 0) {
            return 1;
        }

        // If already present in DP array
        // then return from it
        if(dp[dices][target] != -1) {
            return dp[dices][target];
        }

        long long ans = 0;
        // Iterating over each of the faces
        for(int i = 1; i <= faces; i++) {
            // For the next roll dice will decrease by 1 
            // and target will decrease by (target - current face value)
            ans += (numRollsToTargetHelper(dices-1, faces, target-i, dp) % 1000000007);
        }

        return dp[dices][target] = ans;
    }


    int numRollsToTarget(int n, int k, int target) {
        // Using Recursive Way:
        // return numRollsToTargetRecursive(n, k, target);
        
        // Using Memoization:
        // Since 2 variables dice and target changes in 
        // recursive way, so we created 2D array for DP
        vector<vector<long long>> dp(n+1, vector<long long>(target+1, -1));
        long long ans = numRollsToTargetHelper(n, k, target, dp);
        return ans % (1000000007);
    }
};