class Solution {
public:

    // Using map + vector
    // T.C. = O(nlogn) for sorting, S.C. = O(n) for map and freq
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

    // Using map + priority queue
    // T.C. = O(nlogn) for inserting n elements in prioty queue, S.C. = O(n) for map
    int findLeastUsingPriorityQueue(vector<int>& arr, int k) {

        unordered_map<int, int> mpp;

        // Storing counts of all elements in map
        for(int ele: arr) {
            mpp[ele]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;  // Min Heap

        // Storing frequencies in min heap
        // Minimum frequency will be present at top of min heap after inserting
        for(auto it: mpp) {
            pq.push(it.second);
        }

        while(!pq.empty()) {
            
            // Remaining elements to be removed
            k -= pq.top();

            if(k < 0) {
                // k < 0 means elements can no longer be removed now
                // Size of the remaining min heap gives the count of unique integers
                return pq.size();
            }

            pq.pop();
        }

        return 0;   // All the elements have been removed from freq array
    }

    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // Using map + vector
        // return findLeastUsingMapAnndVector(arr, k);

        // Using map + priority queue
        return findLeastUsingPriorityQueue(arr, k);
    }
};