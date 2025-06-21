class Solution {
public:
    // Brute Force Approach
    // T.C. = O(m*n)
    // S.C. = O(1)
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }

    bool BS(vector<int> &arr, int x) {
        int low = 0, high = arr.size()-1;

        while(low <= high) {
            int mid = (low+high)/2;

            if(arr[mid] == x)
                return true;
            else if(arr[mid] < x) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        return false;
    }
    
    // Better Approach
    // T.C. = O(m) + log(n)
    // S.C. = O(1)
    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        for(int i = 0; i < m; i++) {
            if(target >= matrix[i][0] && target <= matrix[i][n-1]) {
                return BS(matrix[i], target);
            }
        }

        return false;
    }

    // Optimal Approach
    bool searchMatrix3(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = (m*n)-1;

         while(low <= high) {
            int mid = (low+high)/2;

            // Converting 1D index to 2D coordinates
            int row = mid/n, col = mid%n;

            if(matrix[row][col] == target) {
                return true;
            } else if(matrix[row][col] < target) {
                low = mid+1;
            } else {
                high = mid-1;
            }
         }

         return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Brute Force Approach
        // return searchMatrix1(matrix, target);

        // Better Approach
        // return searchMatrix2(matrix, target);

        // Optimal Approach
        return searchMatrix3(matrix, target);

    }
};