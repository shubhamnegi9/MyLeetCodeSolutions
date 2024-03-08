class Solution {
public:
    // Usign Two Pass
    // T.C. = O(2n)
    int usingTwoPass(vector<int> &nums) {
        // Hash array of size (maxElement+1)
        vector<int> hash(101, 0);

        // Storing freq of elements in hash array and keeping track of maxFreq element
        int maxFreq = -1;
        for(int ele: nums) {
            hash[ele]++;
            maxFreq = max(maxFreq, hash[ele]);
        }

        // Finding max freq element and increasing its freq count
        int res = 0;
        for(int i = 0; i < 101; i++) {
            if(hash[i] == maxFreq) {
                res += hash[i];
            }
        }

        // Finding count of maxFreq elements using count() STL function:
        // res = count(hash.begin(), hash.end(), maxFreq) * maxFreq;

        return res;
    }

    // Usign One Pass
    // T.C. = O(n)
    int usingOnePass(vector<int> &nums) {
        // Hash array of size (maxElement+1)
        vector<int> hash(101, 0);

        int maxFreq= -1;
        int res = 0;

        for(int ele: nums) {
            // Increase freq of current element
            hash[ele]++;

            // If the freq of element is more than maxFreq, update maxFreq and reset 'res' and initialize with the element's freq (or initialize with maxFreq)
            if(hash[ele] > maxFreq) {
                maxFreq = hash[ele];
                res = hash[ele];
            }
            // If the freq of element is equal to maxFreq, keep adding it to 'res'
            else if(hash[ele] == maxFreq) {
                res += hash[ele];
            }
        }

        return res;
    }

    int maxFrequencyElements(vector<int>& nums) {
        // Using two pass
        // return usingTwoPass(nums);

        // Usig one pass
        return usingOnePass(nums);
    }
};