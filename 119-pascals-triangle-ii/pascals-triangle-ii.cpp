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
    // T.C. = O(n*r)
    // S.C. = O(n)
    vector<int> getRow1(int rowIndex) {
        vector<int> result;
        int n = rowIndex+1;

        for(int col = 1; col <= n; col++) {
            result.push_back(findNcR(n-1, col-1));
        }
        return result;
    }
    
    vector<int> getRow(int rowIndex) {
        // Brute Force Approach
        return getRow1(rowIndex);
    }
};