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
    
    // T.C. = O(n)
    // S.C. = O(1)
    int missingNumber3(vector<int>& nums) {
        int n = nums.size();
        int totalSum = n*(n+1)/2;
        int sum = 0;
        for(int& ele: nums) {
            sum += ele;
        }
        return totalSum-sum;
    }

    // T.C. = O(2*n)
    // S.C. = O(1)
    int missingNumber4(vector<int>& nums) {
        int n = nums.size();
        int XR = 0;
        for(int i = 0; i <= n; i++) {
            XR ^= i;
        }
        for(int& ele: nums) {
            XR ^= ele;
        }

        return XR;
    }
    
    int missingNumber(vector<int>& nums) {
        // return missingNumber1(nums);

        // return missingNumber2(nums);

        // return missingNumber3(nums);

        return missingNumber4(nums);
    }
};