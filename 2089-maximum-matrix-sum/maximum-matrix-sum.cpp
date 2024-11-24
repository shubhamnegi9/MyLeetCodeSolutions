class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        long long sum = 0;
        int count = 0;
        int minEle = INT_MAX;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int currEleAbs = abs(matrix[i][j]);
                sum += currEleAbs;
                minEle = min(minEle, currEleAbs);
                if(matrix[i][j] < 0)
                    count++;
            }
        }
        
        if(count%2 == 0) {
            return sum;
        } else {
            return sum - 2*minEle;
        }
    }
};