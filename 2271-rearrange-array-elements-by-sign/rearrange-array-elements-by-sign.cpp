class Solution {
public:
    // Approach 1: Brute Force
    // T.C. = O(n) + O(n/2)
    // S.C. = O(n)
    vector<int> rearrangeArray1(vector<int>& nums) {
        vector<int> positives;
        vector<int> negatives;
        
        for(int& ele: nums) {
            if(ele < 0) {
                negatives.push_back(ele);
            } else {
                positives.push_back(ele);
            }
        }
        
        int n = nums.size();
        for(int i = 0; i < n/2; i++) {
            nums[2*i] = positives[i];
            nums[2*i+1] = negatives[i];
        }
        
        return nums;
    }
    
    vector<int> rearrangeArray(vector<int>& nums) {
        // Approach 1: Brute Force
        return rearrangeArray1(nums);
    }
};