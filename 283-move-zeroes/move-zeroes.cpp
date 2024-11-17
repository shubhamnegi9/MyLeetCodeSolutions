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
        int n = nums.size();
        int i = -1;

        for(int j = 0; j < n; j++) {
            if(nums[j] == 0) {
                i = j;
                break;
            }
        }

        if(i != -1) {
            for(int j = i+1; j < n; j++) {
                if(nums[j] != 0) {
                    swap(nums[i], nums[j]);
                    i++;
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