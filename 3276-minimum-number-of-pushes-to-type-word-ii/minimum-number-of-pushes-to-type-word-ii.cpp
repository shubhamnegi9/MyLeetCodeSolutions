class Solution {
public:
    
    static bool cmp(pair<char, int> &p1, pair<char, int> &p2) {
        return p1.second > p2.second;
    }
    
    int minimumPushes(string word) {
        map<char, int> mpp;
        for(char &ch: word) {
            mpp[ch]++;
        }
        
        vector<pair<char, int>> v;
        for(auto it: mpp) {
            v.push_back(it);
        }
        
        sort(v.begin(), v.end(), cmp);
        
        int totalCost = 0;
        for(int i = 0; i < v.size(); i++) {
            int times = (i/8)+1;
            totalCost += (v[i].second * times);
        }
        
        return totalCost;
    }
};