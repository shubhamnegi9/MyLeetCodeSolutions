class Solution {
public:
    // Approach 1: Left rotate array everytime and check if sorted
    // T.C. = O(n^2)
    // S.C. = O(1)
    bool isSorted(vector<int> nums) {
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i-1])
                return false;
        }    
        return true;
    }
    
    bool check1(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            vector<int> copy = nums;
            // Left rotate original array 'i' times
            rotate(copy.begin(), copy.begin()+i, copy.end());
            if(isSorted(copy))
                return true;
        }
        
        return false;
    }
    
    // Approach 2: By counting non-sorted pair of elements
    // T.C. = O(n)
    // S.C. = O(1)
    bool check2(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[i-1])     // non-sorted pair
                count++;
        }
        
        if(nums[n-1] > nums[0])         // non-sorted pair
            count++;
        
        return count <= 1;
    }
    
    bool check(vector<int>& nums) {
        // Approach 1
        // return check1(nums);
        
        // Approach 2
        return check2(nums);
    }
};