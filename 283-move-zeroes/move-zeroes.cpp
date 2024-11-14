class Solution {
public:
    // Brute Force Approach (Using extra space)
    // T.C. = O(n) + O(x) + O(n-x) = O(2n) = O(n), x = number of non-zero elements
    // S.C. = O(x) = O(n)
    void moveZeroes1(vector<int>& nums) {
        
        vector<int> temp;
        int n = nums.size();
        for(int& ele: nums) {
            if(ele != 0)
                temp.push_back(ele);
        }
        
        int nz = temp.size();
        for(int i = 0; i < nz; i++) {
            nums[i] = temp[i];
        }
        
        for(int i = nz; i < n; i++) {
            nums[i] = 0;
        }
    }
    
    // Optimal Approach (Without extra space)
    // T.C. = O(n)
    // S.C. = O(1)
    void moveZeroes2(vector<int>& nums) {
        
        int j = -1;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                j = i;
                break;
            }
        }
        
        if(j != -1) {
            for(int i = j+1; i < n; i++) {
                if(nums[i] != 0) {
                    swap(nums[j], nums[i]);
                    j++;
                }
            }
        }
    }
    
    void moveZeroes(vector<int>& nums) {
        // Brute Force Approach 
        // moveZeroes1(nums);
        
        // Optimal Approach
        moveZeroes2(nums);
    }
};