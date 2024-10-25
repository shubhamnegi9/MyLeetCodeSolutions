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
    
    // Approach 2: Using sorting
    vector<string> removeSubfolders2(vector<string>& folder) {
        // Doing sorting so that the parent folder (if present) can be found before the current folder
        sort(folder.begin(), folder.end());
        vector<string> result;
        
        result.push_back(folder[0]);    // Since folders are sorted, so folder[0] have no parent folder before that. So it cannot be a subfolder
        
        for(int i = 1; i < folder.size(); i++) {
            string currFolder = folder[i];
            string lastFolder = result.back();  // Last element of result vector
            lastFolder+='/';
            if(currFolder.find(lastFolder) != 0) {  // lastFolder is not found in currFolder. 
                                                    // So currFolder cannot be subfolder
                result.push_back(currFolder);
            }
        }
        
        return result;
    }
    
    vector<string> removeSubfolders(vector<string>& folder) {
        // Approach 1: Using Set
        // return removeSubfolders1(folder);
        
        // Approach 2: Using sorting
        return removeSubfolders2(folder);
    }
};