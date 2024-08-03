class Solution {
public:
    
    bool canBeEqualUsingSorting(vector<int>& target, vector<int>& arr) {
        
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        
        return arr == target;
    }
    
    bool canBeEqualUsingHashArray(vector<int>& target, vector<int>& arr) {
        
        vector<int> hash(1001, 0);
        for(int &ele: arr) {
            hash[ele]++;
        }
        for(int &ele: target) {
            hash[ele]--;
        }
        
        for(int &ele: hash) {
            if(ele != 0)
                return false;
        }
        
        return true;
    }
    
    bool canBeEqualUsingHashMap(vector<int>& target, vector<int>& arr) {
        
        map<int, int> mpp;
        
        for(int &ele: arr) {
            // Add given arr elements to map
            mpp[ele]++;
        }
        
        for(int &ele: target) {
            // target element not found in map
            if(mpp.find(ele) == mpp.end()) {
                return false;
            }
            
            mpp[ele]--;
            // If all duplicate target elements found in map then remove it
            if(mpp[ele] == 0)
                mpp.erase(ele);
        }
        
        // Check if map size is empty 
        return mpp.size() == 0;
    }
       
    
    
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        // By sorting two arrays
        // return canBeEqualUsingSorting(target, arr);
        
        // By using hash array/vector
        // return canBeEqualUsingHashArray(target, arr);
        
        // By using hash map
        return canBeEqualUsingHashMap(target, arr);
    }
};