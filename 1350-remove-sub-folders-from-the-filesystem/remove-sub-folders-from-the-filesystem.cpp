class Solution {
public:
    // Approach 1: Using Set
    // T.C. = O(n*L*L) = O(n*L^2)
    // S.C. = O(n)
    vector<string> removeSubfolders1(vector<string>& folder) {
        unordered_set<string> st(folder.begin(), folder.end());     // Add all folders into unordered set
        vector<string> result;
        
        for(string &currFolder: folder) {       // O(n)
            string subFolder = currFolder;
            bool isFound = false;
            while(!subFolder.empty()) {         // O(L)
                // Last index of '/' in tempFolder  
                size_t lastSlashPos = subFolder.find_last_of('/');      // O(L)
                subFolder = subFolder.substr(0, lastSlashPos);          // O(L) 
                if(st.find(subFolder) != st.end()) {    // Current folder is subfolder of another folder
                    isFound = true;
                    break;
                }
            }
            if(!isFound) {
                result.push_back(currFolder);   // Add currFolder in result if it is not a subfolder of another folder
            }
        }
        
        return result;
    }
    
    vector<string> removeSubfolders(vector<string>& folder) {
        return removeSubfolders1(folder);
    }
};