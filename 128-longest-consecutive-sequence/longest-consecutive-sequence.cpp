class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        if(n==0) return 0;
        int longest = 1;
        
        // Inserting into set
        for(int i = 0; i < n; i++) {
            s.insert(nums[i]);
        } 

        for(auto ele: s) {
            // (ele-1) is not found. Then ele will be the first element in consecutive sequence
            if(s.find(ele-1) == s.end()) {
                int cnt = 1;
                int x = ele;
                // Loop until x+1 is found
                while(s.find(x+1) != s.end()) {
                    x = x+1;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};