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

    string frequencySort(string s) {
        
        // Using Multi Map
        return frequencySortUsingMultiMap(s);

    }
};