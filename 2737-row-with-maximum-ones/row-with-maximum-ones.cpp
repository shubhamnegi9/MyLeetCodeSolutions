class Solution {
public:
    // T.C. = O(m*n)
    // S.C. = O(1)
    vector<int> rowAndMaximumOnes1(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int maxCount = 0, index = 0;

        for(int i = 0; i < m; i++) {
            int countOf1s = 0;
            for(int j = 0; j < n; j++) {
                countOf1s += mat[i][j];
            }
            if(countOf1s > maxCount) {
                maxCount = countOf1s;
                index = i;
            }
        }

        return {index, maxCount};
    }
    
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        return rowAndMaximumOnes1(mat);
    }
};