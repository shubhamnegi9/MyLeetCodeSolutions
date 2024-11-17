class Solution {
public:
    // Approach 1: Using Brute Force
    // T.C. = O(n^2)
    // S.C. = O(1)
    int singleNumber1(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(nums[j] == nums[i]) {
                    count++;
                }
            }
            if(count == 1)
                return nums[i];
        }
        
        return -1;
    }
    
    // Approach 2: Better Approach using hash array
    // T.C. = O(3n) = O(n)
    // S.C. = O(mx), mx = maximum element in nums
    int singleNumber2(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        
        vector<int> hash(mx+1, 0);
        
        for(int& ele: nums) {
            hash[ele]++;
        }
        
        for(int i = 0; i < hash.size(); i++) {
            if(hash[i] == 1)
                return i;
        }
        
        return -1;
    }
    
    // Approach 3: Better Approach using hash map
    // T.C. = O(2n)
    // S.C. = O(n)
    int singleNumber3(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        for(int& ele: nums) {
            mp[ele]++;
        }
        
        for(auto it: mp) {
            if(it.second == 1)
                return it.first;
        }
        
        return -1;
    }
    
    // Approach 4: Optimal Approach using XOR
    // T.C. = O(n)
    // S.C. = O(1)
    int singleNumber4(vector<int>& nums) {
        int XOR = 0;
        
        for(int& ele: nums) {
            XOR ^= ele;
        }
        
        return XOR;
    }
    
    int singleNumber(vector<int>& nums) {
        // Approach 1: Using Brute Force
        // return singleNumber1(nums);
        
        // Approach 2: Better Approach using hash array
        // return singleNumber2(nums);
        
        // Approach 3: Better Approach using hash map
        // return singleNumber3(nums);
        
        // Approach 4: Optimal Approach using XOR
        return singleNumber4(nums);
    }
};