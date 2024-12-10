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
    
    // Approach 2: Optimal Approach
    // T.C. = O(n)
    // S.C. = O(n)
    vector<int> rearrangeArray2(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int posIndex = 0, negIndex = 1;
        
        for(int& ele: nums) {
            if(ele < 0) {
                result[negIndex] = ele;
                negIndex+=2;
            } else {
                result[posIndex] = ele;
                posIndex+=2;
            }
        }
        
        return result;
    }
    
    vector<int> rearrangeArray(vector<int>& nums) {
        // Approach 1: Brute Force
        // return rearrangeArray1(nums);
        
        // Approach 2: Optimal Approach
        return rearrangeArray2(nums); 
    }
};