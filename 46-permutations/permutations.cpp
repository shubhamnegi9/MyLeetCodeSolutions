class Solution {
public:
    
    void solve(vector<int>& nums, vector<int>& visited, vector<int>& ans, vector<vector<int>>& result, int n) {
        
        // Base Case
        if(ans.size() == nums.size()) {
            result.push_back(ans);
            return;
        }
        
        for(int i = 0; i < n; i++) {
            if(visited[i] == 0) {
                ans.push_back(nums[i]);
                visited[i] = 1;
                solve(nums, visited, ans, result, n);
                ans.pop_back();
                visited[i] = 0;
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> visited(n, 0);
        vector<int> ans;
        vector<vector<int>> result;
        
        solve(nums, visited, ans, result, n);
        
        return result;
    }
};