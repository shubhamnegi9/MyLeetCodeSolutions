class Solution {
public:
    // Brute Force Approach
    void moveZeroes1(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();

        for(int& num: nums) {
            if(num != 0)
                v.push_back(num);
        }

        int nz = v.size();

        for(int i = 0; i < nz; i++) {
            nums[i] = v[i];
        }

        for(int i = nz; i < n; i++) {
            nums[i] = 0;
        }
    }

    // Optimal Approach
    void moveZeroes2(vector<int>& nums) {
        int n = nums.size();
        int i = -1;

        for(int j = 0; j < n; j++) {
            if(nums[j] == 0) {
                i = j;
                break;
            }
        }

        if(i == -1)
            return;
        
        for(int j = i+1; j < n; j++) {
            if(nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
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