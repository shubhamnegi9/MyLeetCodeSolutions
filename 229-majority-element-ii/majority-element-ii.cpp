class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n*n)
    // S.C. = O(1)
    vector<int> majorityElement1(vector<int>& nums, int n) {
        vector<int> result;
        for(int i = 0; i < n; i++) {
            if(result.empty() || result[0] != nums[i]) {
                int count = 0;
                for(int j = 0; j < n; j++) {
                    if(nums[i] == nums[j])
                        count++;
                }
                if(count > (int)n/3)
                    result.push_back(nums[i]);   
            }
            if(result.size() == 2)
                break;
        }

        return result;
    }
    
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        // Brute Force Approach
        return majorityElement1(nums, n);
    }
};