class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Converting into row wise cumulative sum matrix
        for(int i = 0; i < rows; i++) {
            for(int j = 1; j < cols; j++) {
                matrix[i][j] += matrix[i][j-1];
            }
        }

        // Now we need to find the number of subarrays with sum = target
        // (Applying LC Problem 560 columnwise in downward direction)
        int count = 0;
        for(int colIndex = 0; colIndex < cols; colIndex++) {
            for(int j = colIndex; j < cols; j++) {
                unordered_map<int, int> mpp;
                // Initially storing <0, 1> in map
                mpp.insert({0, 1});
                int cumSum = 0;
                for(int i = 0; i < rows; i++) {
                    cumSum += matrix[i][j] - ((colIndex > 0) ? matrix[i][colIndex-1] : 0);
                    if(mpp.find(cumSum-target) != mpp.end()) {
                        count+= mpp[cumSum-target];
                    }
                    mpp[cumSum]++;
                }
            }
        }

        return count;
    }
};