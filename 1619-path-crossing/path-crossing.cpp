class Solution {
public:
    bool isPathCrossing(string path) {
        pair<int, int> p = {0, 0};
        // Stores visited points in path
        set<pair<int, int>> visited;
        // Adding origin in visited set
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

            // If point is already found in visited set
            if(visited.find(p) != visited.end()) {
               return true;
            }

            // Add current point to visited set
            visited.insert(p);
        }
        return false;
    }
};