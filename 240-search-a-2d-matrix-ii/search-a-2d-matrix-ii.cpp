class Solution {
public:
    // Brute Force Approach
    // T.C. = O(m*n)
    // S.C. = O(1)
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == target)
                    return true;
            }
        }

        return false;
    }

    bool BS(vector<int>& arr, int x) {
        int low = 0, high = arr.size()-1;

        while(low <= high) {
            int mid = (low+high)/2;

            if(arr[mid] == x) {
                return true;
            } else if(arr[mid] < x) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return false;
    }

    // Better Approach
    // T.C. = O(m*log(n))
    // S.C. = O(1)
    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        for(int i = 0; i < m; i++) {
            // if(target >= matrix[i][0] && target <= matrix[i][n-1]) { // Extra check which can be added
                // Only return true if found using binary search, otherwise move to next row
                if(BS(matrix[i], target)) {     // Not to be written as return BS(matrix[i], target);
                    return true;    
                }
            // }
        }
        return false;
    }
    
    // Optimal Approach
    // T.C. = O(m+n)
    // S.C. = O(1)
    bool searchMatrix3(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int row = 0, col = n-1;

        while(row < m && col >= 0) {
            if(matrix[row][col] == target)
                return true; 
            else if(matrix[row][col] < target) {
                row++;
            } else {
                col--;
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