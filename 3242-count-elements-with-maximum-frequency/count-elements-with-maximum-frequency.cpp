class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        // Hash array of size (maxElement+1)
        vector<int> hash(mx+1, 0);

        // Storing freq of elements in hash array
        for(int ele: nums) {
            hash[ele]++;
        }

        // Finding max freq element and increasing its freq count
        int maxFreq = *max_element(hash.begin(), hash.end());
        int count = 0;
        for(int i = 0; i <= mx; i++) {
            if(hash[i] == maxFreq) {
                count += hash[i];
            }
        }

        return count;
    }
};