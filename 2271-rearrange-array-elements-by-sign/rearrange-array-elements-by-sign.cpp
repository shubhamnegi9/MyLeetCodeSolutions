class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
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
};