class Solution {
public:
    bool isPathCrossing(string path) {
        pair<int, int> p = {0, 0};
        set<pair<int, int>> visited;
        visited.insert(p);
        for(auto ch: path) {
            if(ch == 'N') {
                p.second+=1;
            }
            else if(ch == 'E') {
                p.first+=1;
            }
            else if(ch == 'W') {
                p.first-=1;
            }
            else if(ch == 'S') {
                p.second-=1;
            }

            if(visited.find(p) != visited.end()) {
               return true;
            }

            visited.insert(p);
        }
        return false;
    }
};