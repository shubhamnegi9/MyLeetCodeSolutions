class Solution {
public:
    // T.C. = O(n*n)
    // S.C. = O(1)
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        long long sum = 0;
        int countNegative = 0;
        int minEle = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int currEleAbs = abs(matrix[i][j]);
                sum += currEleAbs;
                minEle = min(minEle, currEleAbs);
                if(matrix[i][j] < 0)
                    countNegative++;
            }
        }
        
        if(countNegative%2 == 0) {
            return sum;
        } else {
            return sum - 2*minEle;
        }
    }
};