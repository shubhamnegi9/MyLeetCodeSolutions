class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        set<string> st;
        
        // Storing the obstacle values into set as strings
        for(vector<int> &obs: obstacles) {
            string key = to_string(obs[0]) + "_" + to_string(obs[1]);
            st.insert(key);
        }
        
        int x = 0, y = 0;
        int maxD = 0;
        pair<int, int> dir = {0, 1};    // Initially pointing to north
        
        for(int i = 0; i < commands.size(); i++) {
            
            if(commands[i] == -2) {         // Turn left 90 degrees
                dir = {-dir.second, dir.first};
            }
            else if(commands[i] == -1) {    // Turn right by 90 degrees
                dir = {dir.second, -dir.first};
            }
            else {      // Move forward in that direction step by step
                for(int steps = 0; steps < commands[i]; steps++) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;
                    
                    string newKey = to_string(newX) + "_" + to_string(newY);
                    if(st.find(newKey) != st.end()) {   // New coordinate is obstacle
                        break;
                    }
                    
                    x = newX;
                    y = newY;
                }
            }
            
            maxD = max(maxD, x*x + y*y);
        }
        
        return maxD;
    }
};