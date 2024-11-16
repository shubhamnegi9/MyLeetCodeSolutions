class Solution {
public:
    
    // Brute Force Approach
    // T.C. = O(n-k+1) * O(k) = O(n*k)
    // S.C. = O(k) extra space for solving problem + O(n-k+1) space for returning result 
    bool isSortedAndConsecutive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            if(nums[i-1]+1 != nums[i])
                return false;
        }    
        return true;
    }
    
    vector<int> resultsArray1(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        for(int i = 0; i < n-k+1; i++) {
            int power = -1;
            vector<int> temp(nums.begin()+i, nums.begin()+i+k);
            if(isSortedAndConsecutive(temp)) {
                power = nums[i+k-1];    // Last element of subarray will be maximum 
            }
            result.push_back(power);
        }
        return result;
    }
    
    // Optimal Approach using Sliding Window
    // T.C. = O(n)
    // S.C. = O(n-k+1) space for returning result 
    vector<int> resultsArray2(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n-k+1, -1);
        int count = 1;      // Count of consecutive elements
        
        // Preprocess first window
        // First window will be from index 0 to index k-1
        for(int i = 1; i < k; i++) {
            if(nums[i] == nums[i-1]+1)  
                count++;
            else 
                count = 1;  // Reset count of consecutive elements
        }
        if(count == k) {
            result[0] = nums[k-1];  // Last element of window will be maximum 
        }
        
        // Process futher windows
        // Next window will be from index 1 to index k
        int i = 1;
        int j = k;
        while(j < n) {
            if(nums[j] == nums[j-1]+1) {
                count++;
            } else {
                count = 1;  // Reset count of consecutive elements
            }
            
            if(count >= k) {
                result[i] = nums[j];    // Last element of window will be maximum 
            }
            
            // Slide the window
            i++;
            j++;
        }
        
        return result;
    }
    
    vector<int> resultsArray(vector<int>& nums, int k) {
        // Brute Force Approach
        // return resultsArray1(nums, k);
        
        // Optimal Approach
        return resultsArray2(nums, k);
    }
};