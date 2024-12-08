class Solution {
public:
    int majorityElement1(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(nums[i] == nums[j]) {
                    count++;
                }
            }
            if(count > n/2)
                return nums[i];
        }
        return -1;
    }
    
    int majorityElementUsingHashing(vector<int> &nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        
        for(int& ele: nums) {
            mp[ele]++;
        }
        
        for(auto it: mp) {
            if(it.second> n/2) {
                return it.first;
            }
        }
        
        return -1;
    }

    int majorityElementUsingMooreVoting(vector<int> &nums) {
        int count = 0, majorityEle = 0;
        
        for(int& ele: nums) {
            if(count == 0) {
                majorityEle = ele;
            }
            
            if(ele == majorityEle) {
                count++;
            } else {
                count--;
            }
        }
        
        return majorityEle;
    }

    int majorityElement(vector<int>& nums) {
        // return majorityElement1(nums);
        
        // return majorityElementUsingHashing(nums);

        return majorityElementUsingMooreVoting(nums);
    }
};