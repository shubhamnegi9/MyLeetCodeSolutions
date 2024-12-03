class Solution {
public:
    
    int missingNumber1(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i <= n; i++) {
            bool found = 0;
            for(int j = 0; j < n; j++) {
                if(nums[j] == i) {
                    found = 1;
                    break;
                }
            }
            if(found == 0) {
                return i;
            }
        }
        return -1;
    }
    
    int missingNumber2(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int n = nums.size();
        
        for(int i = 0; i <= n; i++) {
            if(st.find(i) == st.end()) {
                return i;
            }
        }
        
        return -1;
    }
    
    int missingNumber3(vector<int>& nums) {
        int XOR = 0;
        int n = nums.size();
        for(int i = 0; i <= n; i++) {
            XOR ^= i;
        }
        
        for(int ele: nums) {
            XOR ^= ele;
        }
        
        return XOR;
    }
    
    int missingNumber4(vector<int>& nums) {
        int n = nums.size();
        int totalSum = n*(n+1)/2;
        
        int sum = 0;
        for(int ele: nums) {
            sum+=ele;
        }
        
        return totalSum-sum;
    }
    
    int missingNumber(vector<int>& nums) {
        // return missingNumber1(nums);
        
        // return missingNumber2(nums);
        
        // return missingNumber3(nums);
        
        return missingNumber4(nums);
    }
};