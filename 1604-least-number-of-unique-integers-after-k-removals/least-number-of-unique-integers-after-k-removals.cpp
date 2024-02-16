class Solution {
public:

    int findLeastUsingMapAnndVector(vector<int>& arr, int k) {

        unordered_map<int, int> mpp;

        // Storing counts of all elements in map
        for(int ele: arr) {
            mpp[ele]++;
        }

        vector<int> freq;

        // Storing frequencies in vector
        for(auto it: mpp) {
            freq.push_back(it.second);
        }

        // Sorting in increasing frequency
        sort(freq.begin(), freq.end());

        for(int i = 0; i < freq.size(); i++) {
            
            // Remaining elements to be removed
            k -= freq[i];

            if(k < 0) {
                // k < 0 means elements can no longer be removed now
                // Size of the remaining freq array gives the count of unique integers
                return freq.size() - i;
            }
        }

        return 0;   // All the elements have been removed from freq array
    }

    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // Using map + vector
        return findLeastUsingMapAnndVector(arr, k);
    }
};