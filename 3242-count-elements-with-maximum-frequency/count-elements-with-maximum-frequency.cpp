class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> hash(mx+1, 0);

        for(int ele: nums) {
            hash[ele]++;
        }

        int maxFreq = -1;
        for(int i = 0; i <= mx; i++) {
            if(hash[i] > maxFreq) {
                maxFreq = hash[i];
            }
        }

        int count = 0;
        for(int i = 0; i <= mx; i++) {
            if(hash[i] == maxFreq)
                count+=hash[i];
        }

        return count;
    }
};