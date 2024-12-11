class Solution {
public:
    vector<int> rearrangeArray1(vector<int>& nums) {
        vector<int> positives;
        vector<int> negatives;
        
        for(int& ele: nums) {
            if(ele > 0)
                positives.push_back(ele);
            else
                negatives.push_back(ele);
        }
        
        int n = nums.size();
        for(int i = 0; i < n/2; i++) {
            nums[2*i] = positives[i];
            nums[2*i+1] = negatives[i];
        }
        
        return nums;
    }
    
    vector<int> rearrangeArray2(vector<int>& nums) {
        int posIndex = 0, negIndex = 1;
        int n = nums.size();
        vector<int> result(n, 0);
        
        for(int& ele: nums) {
            if(ele > 0) {
                result[posIndex] = ele;
                posIndex+=2;
            } else{
                result[negIndex] = ele;
                negIndex+=2;
            }
        }
        
        return result;
    }
    
    vector<int> rearrangeArray(vector<int>& nums) {
        // return rearrangeArray1(nums);
        
        return rearrangeArray2(nums);
    }
};