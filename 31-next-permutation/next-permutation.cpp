class Solution {
public:
    void solve(vector<int>& nums, int i, vector<int>& ans, vector<int>& visited, set<vector<int>>& st, int n) {
        // Base case
        if(ans.size() == n) {
            st.insert(ans);
            return;
        }
        
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                visited[i] = 1;
                ans.push_back(nums[i]);
                solve(nums, i+1, ans, visited, st, n);
                visited[i] = 0;
                ans.pop_back();
            }
        }
    }
    
    set<vector<int>> generateAllPermutations(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> visited(n, 0);
        set<vector<int>> st;
        solve(nums, 0, ans, visited, st, n);
        return st;
    }
    
    void nextPermutation1(vector<int>& nums) {
        set<vector<int>> allPermutations = generateAllPermutations(nums);
        
        auto itr = allPermutations.find(nums);
        auto nextItr = next(itr);
        
        if(nextItr != allPermutations.end()) {
            nums = *nextItr;
        } else {
            nums = *allPermutations.begin();
        }
    }
    
    void nextPermutation2(vector<int>& nums) {
        int n = nums.size();
        
        int index = -1;
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                index = i;
                break;
            }
        }
        
        if(index == -1) {
            return reverse(nums.begin(), nums.end());
        }
        
        for(int i = n-1; i > index; i--) {
            if(nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }
        
        reverse(nums.begin()+index+1, nums.end());
    }
    
    void nextPermutation(vector<int>& nums) {
        // return nextPermutation1(nums);
        
        return nextPermutation2(nums);
    }
};