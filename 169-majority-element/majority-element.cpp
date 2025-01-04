class Solution {
public:
    // T.C. = O(n^2)
    // S.C. = O(1)
    int majorityElement1(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = i ; j < n; j++) {
                if(nums[j] == nums[i])
                    count++;
            }
            if(count > n/2)
                return nums[i];
        }

        return -1;
    }

    // T.C. = O(2n)
    // S.C. = O(n)
    int majorityElement2(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int& ele: nums) {
            mp[ele]++;
        }

        for(auto it: mp) {
            if(it.second > n/2)
                return it.first;
        }
        return -1;
    }

    // T.C. = O(n)
    // S.C. = O(1)
    int majorityElement3(vector<int>& nums) {
        int n = nums.size();
        int majorityEle = nums[0];
        int count = 1;

        for(int i = 1; i < n; i++) {
            if(count == 0) {
                majorityEle = nums[i];
                count = 1;
            }
            else if(nums[i] == majorityEle)
                count++;
            else
                count--;
        }
        return majorityEle;
    }
    
    int majorityElement(vector<int>& nums) {
        // return majorityElement1(nums);

        // return majorityElement2(nums);

        return majorityElement3(nums);
    }
};