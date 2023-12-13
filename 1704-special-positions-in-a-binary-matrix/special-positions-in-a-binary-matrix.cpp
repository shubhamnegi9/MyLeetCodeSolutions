class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int isSpecial = 0;
        int specialCount = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(mat[i][j] == 1) {
                    isSpecial = 1;
                    // Making current element 0 and checking along rows and cols
                    mat[i][j] = 0;
                    // Checking along column
                    for(int k = 0; k < rows; k++) {
                        if(mat[k][j] == 1) {
                            isSpecial = 0;
                            break;
                        }
                    }
                    // Checking along row
                    for(int k = 0; k < cols; k++) {
                        if(mat[i][k] == 1) {
                            isSpecial = 0;
                            break;
                        }
                    }
                    if(isSpecial == 1)
                        specialCount++;
                    // Resetting current element to 1 
                    mat[i][j] = 1;
                }
            }
        }

        return specialCount;
    }
};