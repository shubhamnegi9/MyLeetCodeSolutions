class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
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
};