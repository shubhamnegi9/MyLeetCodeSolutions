class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> st;
        map<int, int> mpp;
        for(auto ele: matches) {
            // Inserting all players that have played at least one match in set
            st.insert(ele[0]);
            // Storing frequency of mathes lost by loosers
            mpp[ele[1]]++;
        }

        vector<int> winners, loosers;
        for(auto ele: st) {
            // Players who have not lost any match are winners
            if(mpp[ele] == 0)
                winners.push_back(ele);
        }
        for(auto it: mpp) {
            // Players who have lost exactly one match
            if(it.second == 1)
                loosers.push_back(it.first);
        }
        return {winners, loosers};
    }
};