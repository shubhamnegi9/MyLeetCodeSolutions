class Solution {
public:
    
    bool canBeEqualUsingSorting(vector<int>& target, vector<int>& arr) {
        
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        
        return arr == target;
    }
    
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        return canBeEqualUsingSorting(target, arr);
    }
};