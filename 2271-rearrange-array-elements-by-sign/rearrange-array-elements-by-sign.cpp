class Solution {
public:
    // T.C. = O(n) + O(n/2)
    // S.C. = O(n)
    vector<int> rearrangeArray1(vector<int>& nums) {
        int n = nums.size();
        vector<int> positives;
        vector<int> negatives;

        for(int& num: nums) {
            if(num < 0)
                negatives.push_back(num);
            else
                positives.push_back(num);
        }

        for(int i = 0; i < n/2; i++) {
            nums[2*i] = positives[i];
            nums[2*i+1] = negatives[i];
        }

        return nums;
    }

    // T.C. = O(n)
    // S.C. = O(1)
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