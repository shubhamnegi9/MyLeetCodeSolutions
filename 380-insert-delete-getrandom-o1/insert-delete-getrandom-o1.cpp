class RandomizedSet {
public:
    vector<int> v;  // Vector for storing the elements
    unordered_map<int, int> mpp;    // Map for storing the indexes of vector elements
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        // If element found in map return false
        // T.C. for finding in unordered map is O(1)
        if(mpp.find(val) != mpp.end()) {
            return false;
        }

        // If element not found in map then inserting it in vector
        // T.C. for inserting at end of vector is O(1)
        v.push_back(val);
        // Storing index of vector element in unordered map. T.C. = O(1)
        mpp[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        // If element not found in map return false
        // T.C. for finding in unordered map is O(1)
        if(mpp.find(val) == mpp.end()) {
            return false;
        }

        // If element found in map then removing it from vector
        // Swapping the current element and last element in vector and updating in map. O(1) time:
        int index = mpp[val];
        int lastElement = v.back();
        v.back() = val;
        v[index] = lastElement;
        mpp[lastElement] = index;
        // Remove the current element present at last by popping in O(1) time:
        v.pop_back();
        // Removing current element from map:
        mpp.erase(val); 
        return true;
    }
    
    int getRandom() {
        /*
            [rand() % n] returns a random number from 0 to n-1
        */
        int index = rand() % v.size(); // Returns random number from 0 to (v.size()-1)
        // Returning element present at random index from vector
        return v[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */