class Solution {
public:
    
    vector<int> rearrangeArray1(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        vector<int> positives;
        vector<int> negatives;
        
        for(int& ele: nums) {
            if(ele < 0)
                negatives.push_back(ele);
            else
                positives.push_back(ele);
        }
        
        for(int i = 0; i < n/2; i++) {
            result[2*i] = positives[i];
            result[2*i+1] = negatives[i];
        }
        
        return result;
    }
    
    vector<int> rearrangeArray2(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        int posIndex = 0, negIndex = 1;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] < 0) {
                result[negIndex] = nums[i];
                negIndex+=2;
            } else {
                result[posIndex] = nums[i];
                posIndex+=2;
            }
        }
        
        return result;
    }
    
    vector<int> rearrangeArray(vector<int>& nums) {
        // return rearrangeArray1(nums);
        
        return rearrangeArray2(nums);
    }
};