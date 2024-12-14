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
        T.C. = O(n! * n) + O(n!)
        S.C. = O(n) + O(n!) 
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
    
    // Optimal Approach using STL
    // T.C. = O(n)
    // S.C. = O(1)
    void nextPermutation2(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
    
    // Optimal Approach without STL
    // T.C. = O(3*n)
    // S.C. = O(1)
    void nextPermutation3(vector<int>& nums) {
        int index = -1;
        int n = nums.size();
        
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                index = i;
                break;
            }
        }
        
        if(index == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            for(int i = n-1; i > index; i--) {
                if(nums[i] > nums[index]) {
                    swap(nums[index], nums[i]);
                    break;
                }
             }
            
            reverse(nums.begin()+index+1, nums.end());
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        // Brute Force Approach
        // return nextPermutation1(nums);
        
        // Optimal Approach using STL
        // return nextPermutation2(nums);
        
        // Optimal Approach without STL
        return nextPermutation3(nums);
    }
};