class Solution {
public:
    
    int findnCr(int n, int r) {     // O(numRows)
        int res = 1;
        for(int i = 0; i < r; i++) {
            res *= (n-i);
            res /= (i+1);
        }
        return res;
    }
    
    // Brute Force Approach
    // T.C. = O(numRows*numRows) * O(numRows)
    // S.C. = O(1) extra space
    vector<vector<int>> generate1(int numRows) {
        vector<vector<int>> result(numRows);
        
        for(int r = 1; r <= numRows; r++) {
            result[r-1] = vector<int>(r);
            for(int c = 1; c <= r; c++) {
                result[r-1][c-1] = findnCr(r-1, c-1);
            }
        }
        
        return result;
    }
    
    vector<int> generateRow(int n) {     // O(numRows)
        vector<int> ans;
        int res = 1;
        ans.push_back(res);
        for(int i = 1; i < n; i++) {
            res *= (n-i);
            res /= i;
            ans.push_back(res);
        }
        return ans;
    }
    
    // Optimal Approach 1
    // T.C. = O(numRows*numRows)
    // S.C. = O(1) extra space
    vector<vector<int>> generate2(int numRows) {
        vector<vector<int>> result(numRows);
        
        for(int r = 1; r <= numRows; r++) {
            result[r-1] = generateRow(r);
        }
        
        return result;  
    }
    
    vector<vector<int>> generate(int numRows) {
        // Brute Force Approach
        return generate1(numRows);
        
        // Optimal Approach 1
        // return generate2(numRows);
    }
};