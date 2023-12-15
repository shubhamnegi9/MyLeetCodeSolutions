class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, vector<string>> mpp;
        string res = "";
        for(auto it: paths) {
            mpp[it[0]].push_back("IN");
            mpp[it[1]].push_back("OUT");
        }

        for(auto it: mpp) {
            // cout << it.first;
            // for(auto it2: it.second) {
            //     cout << it2 << " ";
            // }

            if(it.second.size() == 1 && it.second[0] == "OUT")
                res = it.first;
        }
        // cout << endl;

        return res;
    }
};