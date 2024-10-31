class Solution {
public:
    int n;
    
    // Recursive Approach
    // T.C. = O(2^n)
    // S.C. = O(H), H = Height of recursive tree
    int solve(vector<int> &nums, int i, int P) {
        
        // Base Case
        if(i >= n) {
            return 0;
        }
        
        // Take element nums[i] in LIS
        int take = 0;
        if(P == -1 || nums[i] > nums[P]) {
            take = 1 + solve(nums, i+1, i);     // Set current index as P to further recursive call
        }

        // Skip element nums[i] from LIS
        int skip = solve(nums, i+1, P);         // Pass previous value of P to further recursive call
        
        return max(take, skip);
    }
    
    // Top Down Memoization Approach
    // T.C. = O(n*n)
    // S.C. = O(n*n)
    int solveMemo(vector<int> &nums, int i, int P, vector<vector<int>> &dp) {
        
        // Base Case
        if(i >= n) {
            return 0;
        }
        
        if(P != -1 && dp[i][P] != -1)
            return dp[i][P];
        
        // Take element nums[i] in LIS
        int take = 0;
        if(P == -1 || nums[i] > nums[P]) {
            take = 1 + solveMemo(nums, i+1, i, dp);     // Set current index as P to further recursive call
        }

        // Skip element nums[i] from LIS
        int skip = solveMemo(nums, i+1, P, dp);         // Pass previous value of P to further recursive call
        
        if(P != -1) {
            dp[i][P] = max(take, skip);
        }
        
        return max(take, skip);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        
        // Recursive Approach
        // return solve(nums, 0, -1);
        
        // Top Down Memoization Approach
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solveMemo(nums,  0, -1, dp);
        
    }
};