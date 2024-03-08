class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // Hash array of size (maxElement+1)
        vector<int> hash(101, 0);

        // Storing freq of elements in hash array and keeping track of maxFreq element
        int maxFreq = -1;
        for(int ele: nums) {
            hash[ele]++;
            maxFreq = max(maxFreq, hash[ele]);
        }

        // Finding max freq element and increasing its freq count
        int count = 0;
        for(int i = 0; i < 101; i++) {
            if(hash[i] == maxFreq) {
                count += hash[i];
            }
        }

        return count;
    }
};