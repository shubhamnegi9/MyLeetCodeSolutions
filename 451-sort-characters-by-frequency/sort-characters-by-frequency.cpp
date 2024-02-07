class Solution {
public:
    string frequencySortUsingMultiMap(string s) {
        map<char, int> mpp;

        // Storing frequency of each character in map
        for(char &ch: s) {
            mpp[ch]++;
        }

        // In multimap, multiple keys can be mapped to a single value but the keys are stored
        // in sorted order
        multimap<int, char> multiMpp;

        // Insert all pairs from the given map into multimap using the originals map’s value 
        // as a key in the multimap and original map's key as a value in the multimap.
        // This will sort the map in increasing order of frequency as key
        for(auto& it: mpp) {
            multiMpp.insert({it.second, it.first});
        }

        string res;
        // Since we need to sort in descending order, so iterating in reverse order
        for(auto it = multiMpp.rbegin(); it != multiMpp.rend(); it++) {
            char ch = it->second;
            int freq = it->first;
            // Creating a new string using ch times freq
            // Eg. if ch = 'a' and freq = 3, then temp = "aaa"
            string temp = string(freq, ch);
            res += temp;
        }

        return res;
    }

    typedef pair<char, int> P;  // Defining type as P to get clean code
    string frequencySortUsingVectorOfPairs(string s) {
        // Creating vector of size 123 as ASCII value of 'z' is 122
        vector<P> v(123);

        // Storing the character and its frequency as pair in v
        for(char& ch: s) {
            int freq = v[ch].second;
            v[ch] = {ch, freq+1};
        }

        // Lambda function for returning the pairs in decreasing order of second value in pair
        // (& is passed to [&] to pass by reference)
        auto cmp = [&] (P &p1, P &p2) {
            return p1.second > p2.second;
        };
        
        // Sorting the vector based on comparator
        sort(v.begin(), v.end(), cmp);

        string res = "";
        for(int i = 0; i < 123; i++) {
            int ch = v[i].first;
            int freq = v[i].second;
            // Creating a new string using ch times freq
            // Eg. if ch = 'a' and freq = 3, then temp = "aaa"
            string temp = string(freq, ch);
            res+=temp;
        }

        return res;
    }

    // Comparator lambda 
    struct lambda {
        bool operator()(P &p1, P &p2) {
            // Creates a Max heap by placing smaller values at bottom and larger values at top
            return p1.second < p2.second;    
            // For creating Min Heap: return p1.second > p2.second
        }
    };

    string frequencySortUsingMaxHeap(string s) {
        unordered_map<char, int> mpp;

        // Storing character's frequency in map
        for(char& ch: s) {
            mpp[ch]++;
        }

        // Defining priority queue of type P (where P is pair<int, char>) and comparator lambda
        // to make it a Max Heap
        priority_queue<P, vector<P>, lambda> pq;

        // Inserting values from map to Max Heap
        for(auto it: mpp) {
            pq.push({it.first, it.second});
        }

        string res = "";
        while(!pq.empty()) {
            P temp = pq.top();  // returns maximum frequency pair
            pq.pop();
            res += string(temp.second, temp.first); // Creating string from pair and adding to res
        }

        return res;
    }

    string frequencySort(string s) {
        
        // Using Multi Map
        // return frequencySortUsingMultiMap(s);

        // Using vector of pairs
        // return frequencySortUsingVectorOfPairs(s);

        // Using priority queue (Max Heap)
        return frequencySortUsingMaxHeap(s);

    }
};