class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        // Vectors for stroing 1's along row and column
        vector<int> rowCount(rows, 0);
        vector<int> colCount(cols, 0);

        // Traversing in matrix and filling rowCount and colCount
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(mat[i][j] == 1) {
                    rowCount[i]+=1;
                    colCount[j]+=1;
                }
            }
        }

        int countSpecial = 0;
        // Traversing in matrix again and checking for special positions
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(mat[i][j] == 1) {
                    // If only single 1 along the row and column, 
                    // then it is special position
                    if(rowCount[i] ==  1 && colCount[j] == 1) {
                        countSpecial++;
                    }
                }
            }
        }

        return countSpecial;
    }
};