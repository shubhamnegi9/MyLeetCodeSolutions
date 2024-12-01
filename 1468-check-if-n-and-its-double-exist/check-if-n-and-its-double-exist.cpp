class Solution {
public:
    // Approach 1: Using brute force
    // T.C. = O(n^2)
    // S.C. = O(1)
    bool checkIfExist1(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < n; j++) {
                if(i != j && (arr[j] == 2*arr[i] || (arr[i] % 2 == 0 && arr[j] == arr[i]/2))) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool checkIfExist4(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = i; 
        }
        
        for(int i = 0; i < arr.size(); i++) {
            if(mp.find(arr[i]*2) != mp.end() && i != mp[arr[i]*2]) {
                return true;
            }
        }
        return false;
    }
    
    bool checkIfExist(vector<int>& arr) {
        // Approach 1: Using brute force
        return checkIfExist1(arr);
        
        // Approach 4: Using map
        // return checkIfExist4(arr);
    }
};