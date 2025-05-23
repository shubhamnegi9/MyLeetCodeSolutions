class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n) + O(n/2)
    // S.C. = 2*O(n/2)
    vector<int> rearrangeArray1(vector<int>& nums, int n) {
        vector<int> positives, negatives;

        for(int& ele: nums) {
            if(ele >= 0)
                positives.push_back(ele);
            else
                negatives.push_back(ele); 
        }

        for(int i = 0; i < n/2; i++) {
            nums[2*i] = positives[i];
            nums[2*i+1] = negatives[i];
        }

        return nums;
    }
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        // Brute Force Approach
        return rearrangeArray1(nums, n);
    }
};