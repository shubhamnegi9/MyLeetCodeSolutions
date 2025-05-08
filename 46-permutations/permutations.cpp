class Solution {
public:

    void solve(vector<int>& nums, vector<vector<int>>& result, vector<int>& ans, vector<int>& visited, int n) {
        // Base Case
        if(ans.size() == n) {
            result.push_back(ans);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(visited[i] == 0) {
                ans.push_back(nums[i]);
                visited[i] = 1;
                solve(nums, result, ans, visited, n);
                
                // Reset values while backtracking
                visited[i] = 0;
                ans.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> ans;
        vector<int> visited(n, 0);
        solve(nums, result, ans, visited, n);
        return result;
    }
};