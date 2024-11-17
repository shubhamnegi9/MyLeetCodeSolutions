class Solution {
public:
    // Approach 1: Brute Force
    // T.C. = O(n^2)
    // S.C. = O(1)
    int missingNumber1(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i <= n; i++) {
            int found = 0;
            for(int j = 0; j < n; j++) {
                if(nums[j] == i) {
                    found = 1;
                    break;
                }
            }
            if(found == 0)
                return i;
        }
        return -1;
    }
    
    // Approach 2: Better Approach using Hashing
    // T.C. = O(2n) = O(n)
    // S.C. = O(n)
    int missingNumber2(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n+1, 0);
        
        for(int i = 0; i < n; i++) {
            hash[nums[i]] = 1;
        }
        
        for(int i = 0; i <= n; i++) {
            if(hash[i] == 0)
                return i;
        }
        
        return -1;
    }
    
    // Approach 3: Better Approach using Set
    // T.C. = O(n)
    // S.C. = O(n)
    int missingNumber3(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int n = nums.size();
        
        for(int i = 0; i <= n; i++) {
            if(st.find(i) == st.end())
                return i;
        }
        
        return -1;
    }
    
    // Approach 4: Optimal Approach by finding sum
    int missingNumber4(vector<int>& nums) {
        int n = nums.size();
        int sum = (n*(n+1))/2;
        
        int currSum = 0;
        for(int& ele: nums) {
            currSum+=ele;
        }
            
        return sum - currSum;
    }
    
    // Approach 5: Optimal Approach by finding XOR
    int missingNumber5(vector<int>& nums) {
        int n = nums.size(); 
        int XOR1 = 0, XOR2 = 0;
        
        for(int i = 0; i < n; i++) {
            XOR2 ^= nums[i];
            XOR1 ^= i;
        }
        XOR1 ^= n;
        
        return XOR1 ^ XOR2;
    }
    
    int missingNumber(vector<int>& nums) {
        // Approach 1: Brute Force
        // return missingNumber1(nums);
        
        // Approach 2: Better Approach using Hashing
        // return missingNumber2(nums);
        
        // Approach 3: Better Approach using Set
        // return missingNumber3(nums);
        
        // Approach 4: Optimal Approach by finding sum
        // return missingNumber4(nums);
        
        // Approach 5: Optimal Approach by finding XOR
        return missingNumber5(nums);
    }
};