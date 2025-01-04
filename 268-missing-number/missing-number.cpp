class Solution {
public:
    // T.C. = O(n^2)
    // S.C. = O(1)
    int missingNumber1(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i <= n; i++) {
            int found = false;
            for(int& ele: nums) {
                if(ele == i) {
                    found = true;
                    break;
                }
            }
            if(!found)
                return i;
        }
        return -1;
    }

    // T.C. = O(n) for inserting in set + O(n) for finding missing number
    // S.C. = O(n) for set
    int missingNumber2(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        
        for(int i = 0; i <= n; i++) {
            if(st.find(i) == st.end()) {
                return i;
            }
        }
        return -1;
    }
    
    int missingNumber(vector<int>& nums) {
        // return missingNumber1(nums);

        return missingNumber2(nums);
    }
};