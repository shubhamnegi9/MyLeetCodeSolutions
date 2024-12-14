class Solution {
public:
    void solve(vector<int>& nums, vector<int>& visited, vector<int>& ans, set<vector<int>>& result, int n) {
        // Base Case
        if(ans.size() == nums.size()) {
            result.insert(ans);
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
    
    set<vector<int>> getAllPermutations(vector<int>& nums) {
        int n = nums.size();
        vector<int> visited(n, 0);
        vector<int> ans;
        set<vector<int>> result;
        
        solve(nums, visited, ans, result, n);
        
        return result;
    }
    
    /*
        Brute Force Approach
        T.C. = O(N! * N) + O(N!)
        S.C. = O(N) + O(N!) 
    */
    void nextPermutation1(vector<int>& nums) {
        // Set of vector is taken to get all unique and ordered permuations
        set<vector<int>> allPermutations = getAllPermutations(nums);
        
        // for(vector<int> v: allPermutations) {
        //     for(int& ele: v) {
        //         cout << ele << " ";
        //     }
        //     cout << endl;
        // }
        
        auto it = allPermutations.find(nums);
        if(it != allPermutations.end()) {
            auto nextIt = next(it);
            
            if(nextIt != allPermutations.end()) {
                nums = *nextIt;
            } else {
                nums = *allPermutations.begin();
            }
        }   
    }
    
    // Better Approach
    void nextPermutation2(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
    
    void nextPermutation(vector<int>& nums) {
        // Brute Force Approach
        // return nextPermutation1(nums);
        
        // Better Approach
        return nextPermutation2(nums);
    }
};