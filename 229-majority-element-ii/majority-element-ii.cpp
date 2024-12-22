class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(1) extra space
    vector<int> majorityElement1(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        
        for(int i = 0; i < n; i++) {
            if(result.empty() || result[0] != nums[i]) {
                int count = 0;
                for(int j = 0; j < n; j++) {
                    if(nums[j] == nums[i])
                        count++;
                }
                if(count > n/3)
                    result.push_back(nums[i]);
            }
            if(result.size() == 2) {
                break;
            }
        }
        
        return result;
    }
    
    // Better Approach
    // T.C. = O(n)
    // S.C. = O(n)
    vector<int> majorityElement2(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int minCount = (n/3)+1;
        vector<int> result;
            
        for(int& ele: nums) {
            mp[ele]++;
            if(mp[ele] == minCount)
                result.push_back(ele);
            
            if(result.size() == 2)
                break;
        }
        
        return result;
    }
    
    // Optimal Approach    
    // T.C. = O(n) + O(n)
    // S.C. = O(1) 
    vector<int> majorityElement3(vector<int>& nums) {
        int n = nums.size();
        int ele1 = INT_MIN, ele2 = INT_MIN, count1 = 0, count2 = 0;
        
        for(int& num: nums) {
            if(count1 == 0 && num != ele2) {
                count1 = 1;
                ele1 = num;
            } 
            else if(count2 == 0 && num != ele1) {
                count2 = 1;
                ele2 = num;
            }
            else if(num == ele1) {
                count1++;
            }
            else if(num == ele2) {
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }
        
        // Checking if el1 and el2 are majority element or not
        int minCount = (n/3)+1;
        vector<int> result;
        count1 = 0, count2 = 0;
        for(int& num: nums) {
            if(num == ele1) 
                count1++;
            if(num == ele2)
                count2++;
        }
        if(count1 >= minCount)
            result.push_back(ele1);
        if(count2 >= minCount)
            result.push_back(ele2);
        
        return result;
    }
    
    
    vector<int> majorityElement(vector<int>& nums) {
        // Brute Force Approach
        // return majorityElement1(nums);
        
        // Better Approach
        // return majorityElement2(nums);
        
        // Optimal Approach 
        return majorityElement3(nums);
    }
};