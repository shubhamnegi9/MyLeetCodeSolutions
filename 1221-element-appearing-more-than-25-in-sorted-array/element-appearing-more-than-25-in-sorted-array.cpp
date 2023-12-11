class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> mpp;
        for(auto ele: arr) {
            mpp[ele]++;
        }

        int special;
        int maxi = INT_MIN;
        for(auto ele: mpp) {
            // cout << ele.first << " " << ele.second << " " << maxi << endl;
            if(ele.second > maxi) {
                maxi = ele.second;
                special = ele.first;
            }
        }

        return special;
    }
};