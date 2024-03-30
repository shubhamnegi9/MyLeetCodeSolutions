class Solution {
public:
    //Total count of subarrays having <= k distict elements
    int slidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int i = 0, j = 0;
        int count = 0;

        while(j < n) {
            mp[nums[j]]++;

            while(mp.size() > k) {
                //shrink the window
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);  // Remove entry from map
                i++;
            }

            count += (j-i+1);
            j++;
        }

        return count;
    }

    //Approach-1 (Standard Sliding Window twice - A very good Pattern of Sliding Window Problems)
    //T.C : O(n)
    //S.C : O(n)
    int subarraysWithKDistinct1(vector<int>& nums, int k) {
        return slidingWindow(nums, k) - slidingWindow(nums, k-1);
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Approach 1 
        return subarraysWithKDistinct1(nums, k);
    }
};