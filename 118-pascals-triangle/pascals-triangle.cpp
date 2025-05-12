class Solution {
public:
    int findNcR(int n, int r) {
        long long ans = 1;

        for(int i = 0; i < r; i++) {
            ans *= (n-i);
            ans /= (i+1);
        }

        return (int) ans;
    }

    // Brute Force Approach
    // T.C. = O(n*n*n) = O(n^3)
    // S.C. = O(1) for solving problem
    vector<vector<int>> generate1(int numRows) {
        vector<vector<int>> result;
        for(int r = 1; r <= numRows; r++) {
            vector<int> lis;
            for(int c = 1; c <= r; c++) {
                lis.push_back(findNcR(r-1, c-1));
            }
            result.push_back(lis);
        }

        return result;
    }

    vector<int> generateRow(int n) {
        vector<int> lis;
        int ans = 1;
        lis.push_back(ans);

        for(int i = 1; i < n; i++) {
            ans *= (n-i);
            ans /= i;
            lis.push_back(ans);
        }

        return lis;
    }

    // Optimal Approach
    // T.C. = O(n^2)
    // S.C. = O(1) for solving problem
    vector<vector<int>> generate2(int numRows) {
        vector<vector<int>> result;
        for(int r = 1; r <= numRows; r++) {
            result.push_back(generateRow(r));
        }

        return result;
    }

    // Another Optimal Approach
    vector<vector<int>> generate3(int numRows) {
        vector<vector<int>> result(numRows);

        for(int i = 0; i < numRows; i++) {
            result[i] = vector<int>(i+1, 1);    // Dynamically defining the columns
            for(int j = 1; j < i; j++) {
                result[i][j] = result[i-1][j] + result[i-1][j-1];
            }
        }

        return result;
    }
    
    vector<vector<int>> generate(int numRows) {
        // Brute Force Approach
        // return generate1(numRows);

        // Optimal Approach
        return generate2(numRows);

        // Another Optimal Approach
        // return generate3(numRows);
    }
};