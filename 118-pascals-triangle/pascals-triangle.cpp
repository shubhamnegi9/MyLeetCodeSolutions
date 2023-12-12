class Solution {
public:
    vector<int> generateRow(int row) {
        long long ans = 1;  // long long taken to avoid overflow
        vector<int> resRow;
        resRow.push_back(ans);
        for(int col = 1; col < row; col++) {
            ans *= (row - col);
            ans /= col;
            resRow.push_back(ans);
        }
        return resRow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 1; i <= numRows; i++) {
            res.push_back(generateRow(i));
        }
        return res;
    }
};