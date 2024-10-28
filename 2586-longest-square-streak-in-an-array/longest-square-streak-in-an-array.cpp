class Solution {
public:
    // Apporach 1: Using Sorting + Map
    // T.C. = O(nlogn) + O(n) = O((nlogn)
    // S.C. = O(n)
    int longestSquareStreak1(vector<int>& nums) {
        sort(nums.begin(), nums.end());     // O(nlogn)
        unordered_map<int, int> mp;
        int maxStreak = 0;
        
        for(int num: nums) {                // O(n)
            int sqrtNum = sqrt(num);
            if(sqrtNum * sqrtNum == num && mp.find(sqrtNum) != mp.end()) {
                mp[num] = mp[sqrtNum]+1;
            } else {
                mp[num] = 1;
            }
            maxStreak = max(maxStreak, mp[num]);
        }
        
        return maxStreak >= 2 ? maxStreak : -1;
    }
    
    // Approach 2: Without sorting + Set
    // T.C. = O(n)
    // S.C. = O(n)
    int longestSquareStreak2(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxStreak = 0;
        
        for(int &num: nums) {            // O(n)
            int streak = 0;
            long long curr = num;
            
            while(st.find(curr) != st.end()) {      // O(5)
                streak++;
                
                if(curr*curr > 1e5) {   // 1e5 = 10^5
                    break;    
                }
                
                curr = curr*curr;
            }
            
            maxStreak = max(maxStreak, streak);
        }
        
        return maxStreak >= 2 ? maxStreak : -1;
    }
    
    // Approach 3: Sorting + Binary Search
    // T.C. = O(nlogn) + O(n * 5*logn)
    // S.C. = O(1)
    bool find(long long curr, vector<int>& nums) {  // O(logn)
        
        int l = 0;
        int r = nums.size()-1;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(nums[mid] == curr) {
                return true;
            }
            else if(nums[mid] > curr) {
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return false;
    }
    
    int longestSquareStreak3(vector<int>& nums) {
        sort(nums.begin(), nums.end());     // O(nlogn)
        int maxStreak = 0;
        
        for(int &num: nums) {       // O(n)
            int streak = 0;
            long long curr = num;
            
            while(find(curr, nums)) {     // O(5)
                streak++;
                
                if(curr*curr > 1e5) {   // 1e5 = 10^5
                    break;
                }
                
                curr = curr*curr;
            }
            
            maxStreak = max(maxStreak, streak);
        }
        
        return maxStreak >= 2 ? maxStreak : -1;
    }
    
    int longestSquareStreak(vector<int>& nums) {
        // Apporach 1: Using Sorting + Map
        // return longestSquareStreak1(nums);
        
        // Approach 2: Without sorting + Set
        // return longestSquareStreak2(nums);
        
        // Approach 3: Sorting + Binary Search
        return longestSquareStreak3(nums);
    }
};