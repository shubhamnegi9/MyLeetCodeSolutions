class Solution {
public:
    // Brute Force Approach
    // T.C. = O(cols*rows*rows)
    vector<vector<char>> rotateTheBox1(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        
        int rows = n;
        int cols = m;
        vector<vector<char>> rotatedBox(rows, vector<char>(cols));
        
        // Finding transpose of box matrix
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                rotatedBox[i][j] = box[j][i];
            }
        }
        
        // Reverse each row to get rotated box
        // Used row as reference (&) as we need to make the changes of each row in rotatedBox also
        for(vector<char>& row: rotatedBox) {   
            reverse(row.begin(), row.end());
        }
        
        // Applying effect of gravity in each column
        // T.C. = O(cols*rows*rows)
        for(int i = 0; i < cols; i++) {
            // Going from bottom to top in each row
            for(int j = rows-1; j >= 0; j--) {
                if(rotatedBox[j][i] == '.') {   // If empty cell
                   for(int k = j-1; k >= 0; k--) {
                       if(rotatedBox[k][i] == '#') {    // If stone cell
                           swap(rotatedBox[j][i], rotatedBox[k][i]);
                           break;
                       }
                       if(rotatedBox[k][i] == '*') {    // If onbstracle cell
                           break;
                       }
                   }
                }
            }
        }
        
        return rotatedBox;
    }
    
    // Optimal Approach
    // T.C. = O(cols*rows)
    vector<vector<char>> rotateTheBox2(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        
        int rows = n;
        int cols = m;
        vector<vector<char>> rotatedBox(rows, vector<char>(cols));
        
        // Finding transpose of box matrix
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                rotatedBox[i][j] = box[j][i];
            }
        }
        
        // Reverse each row to get rotated box
        // Used row as reference (&) as we need to make the changes of each row in rotatedBox also
        for(vector<char>& row: rotatedBox) {   
            reverse(row.begin(), row.end());
        }
        
        // Applying effect of gravity in each column
        // T.C. = O(cols*rows*rows)
        for(int i = 0; i < cols; i++) {
            // Finding first empty cell from bottom in current column
            int j = n-1;
            while(j >= 0) {
                if(rotatedBox[j][i] == '.') {
                    break;
                }
                j--;
            }
            
            // No empty cell found in current column
            // No effect of gravity will be applied in this column
            if(j == -1) {
                continue;
            }
            
            // rotatedBox[j][i] will be storing first empty cell
            for(int k = j-1; k >= 0; k--) {
                // If obstracle found then updating the first empty cell 
                // to be one above this obstracle cell
                if(rotatedBox[k][i] == '*') {
                    j = k-1;
                }
                
                // If stone cell found then swapping its values with empty cell and updating the empty cell
                if(rotatedBox[k][i] == '#') {
                    swap(rotatedBox[j][i], rotatedBox[k][i]);
                    j--;
                }
            }
        }
        
        return rotatedBox;
    }
    
    
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        // Brute Force Approach
        // return rotateTheBox1(box);
        
        // Optimal Approach
        return rotateTheBox2(box);
    }
};