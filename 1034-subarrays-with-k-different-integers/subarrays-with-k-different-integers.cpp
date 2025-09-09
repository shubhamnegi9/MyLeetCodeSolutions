class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(n) for set
    int subarraysWithKDistinct1(vector<int>& nums, int k) {
        int n = nums.size(), count = 0;

        for(int i = 0; i < n; i++) {
            set<int> st;
            for(int j = i; j < n; j++) {
                st.insert(nums[j]);
                if(st.size() == k) {
                    count++;
                } else if(st.size()> k){
                    break;
                }
            }
        }

        return count;
    }

    // Optimal Approach
    // T.C. = 2*O(2n) 
    // S.C. = O(n) for map
    int subarraysWithAtmostKDistinct(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = 0, count = 0;
        map<int, int> mpp;

        while(r < n) {
            mpp[nums[r]]++;

            while(mpp.size() > k) {
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0)
                    mpp.erase(nums[l]);
                l++;
            }

            if(mpp.size() <= k) {
                count += (r-l+1);   // Increase count by size of window
            }

            r++;
        }

        return count;
    }
    
    int subarraysWithKDistinct2(vector<int>& nums, int k) {
        return subarraysWithAtmostKDistinct(nums, k) - subarraysWithAtmostKDistinct(nums, k-1);
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Brute Force Approach
        // return subarraysWithKDistinct1(nums, k);

        // Optimal Approach
        return subarraysWithKDistinct2(nums, k);
    }
};