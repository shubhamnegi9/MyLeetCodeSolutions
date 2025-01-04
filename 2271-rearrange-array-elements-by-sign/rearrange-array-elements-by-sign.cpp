class Solution {
public:
    // T.C. = O(n) + O(n/2)
    // S.C. = O(n)
    vector<int> rearrangeArray1(vector<int>& nums) {
        int n = nums.size();
        vector<int> positives;
        vector<int> negatives;

        for(int& ele: nums) {
            if(ele < 0)
                negatives.push_back(ele);
            else
                positives.push_back(ele);
        }

        for(int i = 0; i < n/2; i++) {
            nums[2*i] = positives[i];
            nums[2*i+1] = negatives[i];
        }

        return nums;
    }

    // T.C. = O(n)
    // S.C. = O(n)
    vector<int> rearrangeArray2(vector<int>& nums) {
        int n = nums.size();
        int positiveIdx = 0, negativeIdx = 1;
        vector<int> result(n, 0);

        for(int i = 0; i < n; i++) {
            if(nums[i] >= 0) {
                result[positiveIdx] = nums[i];
                positiveIdx+=2;
            } else {
                result[negativeIdx] = nums[i];
                negativeIdx+=2;
            }
        }

        return result;
    }

    vector<int> rearrangeArray(vector<int>& nums) {
        // return rearrangeArray1(nums);

        return rearrangeArray2(nums);
    }
};