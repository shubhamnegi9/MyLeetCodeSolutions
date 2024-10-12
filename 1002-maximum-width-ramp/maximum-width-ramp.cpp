class Solution {
public:
    // Approach 1: Brute Force
    // T.C. = O(n^2)
    // S.C. = O(1)
    int maxWidthRamp1(vector<int>& nums) {
        int n = nums.size();
        int ramp = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(nums[i] <= nums[j]) {
                    ramp = max(ramp, j-i);
                }
            } 
        }
        return ramp;
    }
    
    // Approach 2: Better Brute Force
    // T.C. = O(n^2)
    // S.C. = O(1)
    int maxWidthRamp2(vector<int>& nums) {
        int n = nums.size();
        int ramp = 0;
        for(int i = 0; i < n; i++) {
            for(int j = n-1; j > i; j--) {
                if(nums[i] <= nums[j]) {
                    ramp = max(ramp, j-i);
                    break;
                }
            } 
        }
        return ramp;
    }
    
    // Approach 3: Optimal Approach
    // T.C. = O(n)
    // S.C. = O(n)
    int maxWidthRamp3(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxToRight(n, -1);
        
        maxToRight[n-1] = nums[n-1];
        
        for(int i = n-2; i >=0; i--) {
            maxToRight[i] = max(nums[i], maxToRight[i+1]);
        }
        
        int i = 0;
        int j = 0;
        int ramp = 0;
        
        while(j < n) {
            while(i < j && nums[i] > maxToRight[j]) {
                i++;
            }
            
            ramp = max(ramp, j-i);
            j++;
        }
        
        return ramp;
    }
    
    int maxWidthRamp(vector<int>& nums) {
        // Approach 1: Brute Force
        // return maxWidthRamp1(nums);
        
        // Approach 2: Better Brute Force
        // return maxWidthRamp2(nums);
        
        // Approach 3: Optimal Approach
        return maxWidthRamp3(nums);
    }
};