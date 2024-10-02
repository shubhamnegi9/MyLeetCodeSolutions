class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st(arr.begin(), arr.end());
        unordered_map<int, int> mpp;
        
        int rank = 1;
        for(int num: st) {
            mpp[num] = rank;
            rank++;
        }
        
        for(int i = 0; i < arr.size(); i++) {
            arr[i] = mpp[arr[i]];
        }
        
        return arr;
    }
};