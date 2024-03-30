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


    //Approach-2 (One Pass Flow)
    //T.C : O(n)
    //S.C : O(n)
    int subarraysWithKDistinct2(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int i = 0, j = 0, i_largest = 0;
        int count = 0;

        while(j < n) {
            mp[nums[j]]++;

            // Handling Invalid Subarray
            // Shrink the window
            while(mp.size() > k) {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);  // Remove entry from map
                i++;
                i_largest = i;  // Move i_largest to i
            }

            // Handling to find smallest valid subarray ending at j
            while(mp[nums[i]] > 1) {
                mp[nums[i]]--;
                i++;
            }

            // Smallest valid subarray ending at j found
            if(mp.size() == k) {
                count += (i - i_largest + 1);
            } 

            j++;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Approach 1 
        // return subarraysWithKDistinct1(nums, k);

        // Approach 2
        return subarraysWithKDistinct2(nums, k);
    }
};