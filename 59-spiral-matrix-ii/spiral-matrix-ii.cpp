class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int ele = 1;
        int top = 0, bottom = n-1, left = 0, right = n-1;
        vector<vector<int>> mat(n, vector<int>(n, 0));

        while(top <= bottom && left <= right) {
            for(int i = left; i <= right; i++) {
                mat[top][i] = ele;
                ele++;
            }
            top++;

            for(int i = top; i <= bottom; i++) {
                mat[i][right]= ele;
                ele++;
            }
            right--;

            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                    mat[bottom][i] = ele;
                    ele++;
                }
                bottom--;
            }

            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                    mat[i][left] = ele;
                    ele++;
                }
                left++;
            }

        }

        return mat;
    }
};