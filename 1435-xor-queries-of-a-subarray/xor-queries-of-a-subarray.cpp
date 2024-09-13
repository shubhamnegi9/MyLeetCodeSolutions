class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        
        for(vector<int> ele: queries) {
            int start = ele[0];
            int end = ele[1];
            int XOR = arr[start];
            for(int i = start+1; i <= end; i++) {
                XOR ^= arr[i];
            }
            result.push_back(XOR);
        }
        
        return result;
    }
};