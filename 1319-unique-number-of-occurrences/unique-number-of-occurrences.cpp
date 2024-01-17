class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Hashmap for storing occurences of each value
        unordered_map<int, int> hashMap;
        for(auto ele: arr) {
            hashMap[ele]++;
        }
        // Hashmap for storing count of each occourences
        unordered_map<int, int> countHashMap;
        for(auto it: hashMap) {
            countHashMap[it.second]++;
        }
        for(auto it: countHashMap) {
            // If count of occurence is more than one, then it is not unique
            if(it.second > 1)
                return false;
        }
        return true;
    }
};