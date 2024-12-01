class Solution {
public:
    // Approach 1: Using brute force
    // T.C. = O(n^2)
    // S.C. = O(1)
    bool checkIfExist1(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && arr[j] == 2*arr[i]) {
                    return true;
                }
            }
        }
        return false;
    }
    
    // Approach 2: Using Binary Search
    // T.C. = O(nlogn)
    // S.C. = O(1)
    int bSearch(vector<int>& arr, int target) {
        int l = 0; 
        int r = arr.size()-1;
        
        while(l <= r) {
            int mid = l+(r-l)/2;
            if(arr[mid] == target) {
                return mid;
            }
            else if(target < arr[mid]) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return -1;
    }
    
    bool checkIfExist2(vector<int>& arr) {
        int n = arr.size();
        // Sort the array to apply binary search
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < n; i++) {
            int j = bSearch(arr, arr[i]*2);
            if(j != -1 && i != j) {
                return true;
            }
        }
        return false;
    }
    
    // Approach 3: Using Set
    bool checkIfExist3(vector<int>& arr) {
        unordered_set<int> st;
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            if(st.find(arr[i]*2) != st.end() || (arr[i]%2 == 0 && st.find(arr[i]/2) != st.end())) {
                return true;
            }
            st.insert(arr[i]);
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
        // return checkIfExist1(arr);
        
        // Approach 2: Using Binary Search
        // return checkIfExist2(arr);
        
        // Approach 3: Using Set
        return checkIfExist3(arr);
        
        // Approach 4: Using map
        // return checkIfExist4(arr);
    }
};