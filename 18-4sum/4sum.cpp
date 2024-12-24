class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n^4) * O(log(no. of quads))
    // S.C. = 2*O(no. of quads)
    vector<vector<int>> fourSum1(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                for(int k = j+1; k < n; k++) {
                    for(int l = k+1; l < n; l++) {
                        // Taken long long to prevent signed integer overflow
                        long long sum = nums[i]+nums[j];
                        sum += nums[k];
                        sum += nums[l];
                        /*
                            If add all at one time then it exceed integer limit
                            and type casting will fail
                        */
                        if(sum == target) {                    
                            vector<int> quad = {nums[i], nums[j], nums[k], nums[l]};
                            sort(quad.begin(), quad.end());
                            st.insert(quad);
                        }
                    }
                }
            }
        }
        
        vector<vector<int>> result(st.begin(), st.end());
        return result;
    }
    
    // Better Approach
    // T.C. = O(n^3) * O(log(no. of quads))
    // S.C. = 2*O(no. of quads) + O(n) for hashset
    vector<vector<int>> fourSum2(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                unordered_set<int> hashSet; // Declaring here so that we get empty hashSet in every 'j' iteration
                for(int k = j+1; k < n; k++) {
                    long long sum = nums[i]+nums[j];
                    sum+=nums[k];
                    int fourth = target-sum;
                    if(hashSet.find(fourth) != hashSet.end()) {
                        vector<int> quad = {nums[i], nums[j], nums[k], fourth};
                        sort(quad.begin(), quad.end());
                        st.insert(quad);
                    }
                    hashSet.insert(nums[k]);
                }
            }
        }
        
        vector<vector<int>> result(st.begin(), st.end());
        return result;
    }
    
    // Optimal Approach
    // T.C. = O(nlogn) + O(n^3) 
    // S.C. = O(no. of quads) for returning answer
    vector<vector<int>> fourSum3(vector<int>& nums, int target) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) 
                continue;
            
            for(int j = i+1; j < n; j++) {
                if(j != i+1 && nums[j] == nums[j-1])
                    continue;
                
                int k = j+1;
                int l = n-1;
                
                while(k < l) {
                    long long sum = nums[i]+nums[j];
                    sum+= nums[k];
                    sum+= nums[l];
                    
                    if(sum < target) {
                        k++;
                    }
                    else if(sum > target) {
                        l--;
                    }
                    else {
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        
                        while(k < l && nums[k] == nums[k-1]) {
                            k++;
                        }
                        
                        while(k < l && nums[l] == nums[l+1]) {
                            l--;
                        }
                    }
                }
                
            }
        }
        
        return result;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Brute Force Approach
        // return fourSum1(nums, target);
        
        // Better Approach
        // return fourSum2(nums, target);
        
        // Optimal Approach
        return fourSum3(nums, target);
    }
};