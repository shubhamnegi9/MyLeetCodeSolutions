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
    
    // Bottom Up Approach
    // T.C. = O(n*n)
    // S.C. = O(n)
    int solveBottomUp(vector<int> &nums, vector<int> &t) {
        int maxLIS = 1;     // In case whole nums vector have no LIS, max length of LIS should be 1
                            // Eg. nums = [7,7,7,7,7,7,7], LIS = {7}
        
        // t[i] ->  Max length of LIS ending at index j
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    t[i] = max(t[i], t[j]+1);
                }
                maxLIS = max(maxLIS, t[i]);
            }
        }
        
        return maxLIS;
    }
    
    // Using Patience Sorting
    // T.C. = O(n*logn)
    // S.C. = O(length of sorted vector)
    int lengthOfLISUsingPatienceSorting(vector<int>& nums) {
        vector<int> sorted;
        
        for(int i = 0; i < nums.size(); i++) {                                  // O(n)
            auto lb = lower_bound(sorted.begin(), sorted.end(), nums[i]);       // O(logn)
            if(lb == sorted.end()) {            // Lower Bound of nums[i] not found in sorted vector
                sorted.push_back(nums[i]);      // PUSH
            } else {                            // Lower Bound of nums[i] found in sorted vector
                *lb = nums[i];                  // REPLACE
            }
        }
        
        return sorted.size();   // Max length of LIS
    }
    
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        
        // Recursive Approach
        // return solve(nums, 0, -1);
        
        // Top Down Memoization Approach
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solveMemo(nums,  0, -1, dp);
        
        // Bottom Up Approach
        // vector<int> t(n, 1);    // Initially filled with 1s as each element will make LIS on its own
        // return solveBottomUp(nums, t);
        
        // Using Patience Sorting
        return lengthOfLISUsingPatienceSorting(nums);
    }
};