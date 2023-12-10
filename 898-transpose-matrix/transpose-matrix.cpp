class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        // ROWS
        int m = matrix.size();
        // COLUMNS
        int n = matrix[0].size();

        // Creating transpsoe matrix of size (n X m)
        vector<vector<int>> transpose(n, vector<int>(m));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                transpose[j][i] = matrix[i][j];
            }
        }

        return transpose;
    }
};