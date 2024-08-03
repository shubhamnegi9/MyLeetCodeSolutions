class Solution {
public:
    
    bool canBeEqualUsingSorting(vector<int>& target, vector<int>& arr) {
        
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        
        return arr == target;
    }
    
    bool canBeEqualUsingHashing(vector<int>& target, vector<int>& arr) {
        
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
        
    
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        // By sorting two arrays
        // return canBeEqualUsingSorting(target, arr);
        
        // By hashing
        return canBeEqualUsingHashing(target, arr);
    }
};