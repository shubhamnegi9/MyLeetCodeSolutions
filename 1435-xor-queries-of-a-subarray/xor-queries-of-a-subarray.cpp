class Solution {
public:
    // Brute Force Approach
    vector<int> xorQueriesBrute(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        
        for(vector<int> query: queries) {
            int left = query[0];
            int right = query[1];
            int XOR = arr[left];
            for(int i = left+1; i <= right; i++) {
                XOR ^= arr[i];
            }
            result.push_back(XOR);
        }
        
        return result;
    }
    
    // Optimal Approach
    vector<int> xorQueriesOptimal(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        
        vector<int> prefixXOR(n, 0);
        
        // Precomputing prefix XOR
        prefixXOR[0] = arr[0];
        for(int i = 1; i < n; i++) {
            prefixXOR[i] = prefixXOR[i-1] ^ arr[i];
        }
        
        vector<int> result;
        for(vector<int> query: queries) {
            int left = query[0];
            int right = query[1];
            int XORResult = prefixXOR[right] ^ (left == 0 ? 0 : prefixXOR[left-1]);
            result.push_back(XORResult);
        }
        
        return result;
    }
    
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // Brute Force Approach
        // return xorQueriesBrute(arr, queries);
        
        // Optimal Approach
        return xorQueriesOptimal(arr, queries);
    }
};