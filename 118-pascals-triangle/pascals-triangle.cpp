class Solution {
public:
    
    vector<vector<int>> generate1(int numRows) {
        vector<vector<int>> result(numRows);

        for(int i = 0; i < numRows; i++) {
            result[i] = vector<int>(i+1, 1);
            for(int j = 1; j < i; j++) {
                result[i][j] = result[i-1][j] + result[i-1][j-1];
            }
        }

        return result;
    }

    int findnCr(int n, int r) {
        int result = 1;
        for(int i = 0; i < r; i++) {
            result *= (n-i);
            result /= (i+1);
        }

        return result;
    }

    vector<vector<int>> generate2(int numRows) {
        vector<vector<int>> result(numRows);

        for(int i = 1; i <= numRows; i++) {
            result[i-1] = vector<int>(i, 1);
            for(int j = 1; j <= i; j++) {
                result[i-1][j-1] = findnCr(i-1, j-1);
            } 
        }

        return result;
    }

    vector<int> generateRow(int n) {
        int ans = 1;
        vector<int> result;
        result.push_back(ans);
        
        for(int i = 1; i < n; i++) {
            ans *= (n-i);
            ans /= i;
            result.push_back(ans);
        }

        return result;
    }

    vector<vector<int>> generate3(int numRows) {
        vector<vector<int>> result(numRows);
        for(int i = 1; i <= numRows; i++) {
            result[i-1] = generateRow(i);
        }
        return result;
    }
    
    vector<vector<int>> generate(int numRows) {
        // return generate1(numRows);

        // return generate2(numRows);

        return generate3(numRows);
    }
};