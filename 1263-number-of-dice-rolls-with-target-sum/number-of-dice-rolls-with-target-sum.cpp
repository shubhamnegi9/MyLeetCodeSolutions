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


    // Using Memoization (Top-Down Approach)
    long long numRollsToTargetMemo(int dices, int faces, int target, vector<vector<long long>>& dp) {
        
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
            ans += (numRollsToTargetMemo(dices-1, faces, target-i, dp) % 1000000007);
        }

        return dp[dices][target] = ans;
    }


    // Using Bottom-Up Approach
    long long numRollsToTargetBottomUp(int dices, int faces, int target) {
        
        // created 2D array for DP and initialize all with 0 
        // since for invalid dices and target value we returned 0
        vector<vector<long long>> dp(dices+1, vector<long long>(target+1, 0));

        // If no dice and target is also 0 then return 1
        dp[0][0] = 1;

        // Iterating in dices and faces
        // in bottom-up way
        for(int d = 1; d <= dices; d++) {
            for(int t = 1; t <= target; t++) {
                long long ans = 0;
                // Iterating over each of the faces
                for(int i = 1; i <= faces; i++) {
                    // For the next roll dice will decrease by 1 
                    // and target will decrease by (target - current face value)
                    if(t-i >= 0)
                        ans += dp[d-1][t-i] % 1000000007;

                }
                dp[d][t] = ans;
            }
        }

        return dp[dices][target];
    }

    // Using Space Optimized Bottom-Up Approach
    long long numRollsToTargetBottomUpSpaceOpt(int dices, int faces, int target) {
        
        // previous dice row
        vector<long long> prev(target+1, 0);
        // current dice row
        vector<long long> curr(target+1, 0);

        // If no dice and target is also 0 then return 1
        prev[0] = 1;

        // Iterating in dices and faces
        // in bottom-up way
        for(int d = 1; d <= dices; d++) {
            for(int t = 1; t <= target; t++) {
                long long ans = 0;
                // Iterating over each of the faces
                for(int i = 1; i <= faces; i++) {
                    // For the next roll dice will decrease by 1 
                    // and target will decrease by (target - current face value)
                    if(t-i >= 0)
                        ans += prev[t-i] % 1000000007;

                }
                curr[t] = ans;
            }
            // After each iteration assign curr to prev
            prev = curr;
        }

        return prev[target];
    }


    int numRollsToTarget(int n, int k, int target) {
        // Using Recursive Way:
        // return numRollsToTargetRecursive(n, k, target);
        
        /* Using Memoization:
        Since 2 variables 'dices' and 'target' changes in 
        recursive way, so we created 2D array for DP
        and initialize all with -1
        */

        // vector<vector<long long>> dp(n+1, vector<long long>(target+1, -1));
        // long long ans = numRollsToTargetMemo(n, k, target, dp);
        // return ans % (1000000007);

        // Using Bottom-Up Approach:
        // S.C. = O(n*target)
        // long long ans = numRollsToTargetBottomUp(n, k, target);
        // return ans % (1000000007);

        // Using Space Optimized Bottom-Up Approach:
        // S.C. = O(target)
        long long ans = numRollsToTargetBottomUpSpaceOpt(n, k, target);
        return ans % (1000000007);
    }
};