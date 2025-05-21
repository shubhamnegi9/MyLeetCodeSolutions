class Solution {
public:

    int findNcR(int n, int r) {
        long long ans = 1;

        for(int i = 0; i < r; i++) {
            ans *= (n-i);
            ans /= i+1;
        }

        return ans;
    }

    // Brute Force Approach
    // T.C. = O(n*n*r) = O(n^3)
    // S.C. = O(1) for solving the problem
    vector<vector<int>> generate1(int numRows) {
        vector<vector<int>> result;
        for(int n = 1; n <= numRows; n++) {
            vector<int> lis;
            for(int r = 1; r <= n; r++) {
                lis.push_back(findNcR(n-1, r-1));
            }
            result.push_back(lis);
        }

        return result;
    }

    vector<int> generateRow(int n) {
        long long ans = 1;
        vector<int> result;
        result.push_back(ans);

        for(int i = 1; i < n; i++) {
            ans *= (n-i);
            ans /= i;
            result.push_back(ans);
        }
        return result;
    }

    // Optimal Approach 1
    // T.C. = O(n*n)
    // S.C. = O(1) for solving problem
    vector<vector<int>> generate2(int numRows) {
        vector<vector<int>> result;
        for(int n = 1; n <= numRows; n++) {
            result.push_back(generateRow(n));
        }

        return result;
    }
    
    vector<vector<int>> generate(int numRows) {
        // Brute Force Approach
        // return generate1(numRows);

        // Optimal Approach 1
        return generate2(numRows);
    }
};