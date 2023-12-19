class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> smoothen_image(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int sum = 0; 
                int count = 0;
                // Iterating in surrounding cells
                for(int x = i-1; x <= i+1; x++) {
                    for(int y = j-1; y <= j+1; y++) {
                        // Visiting in only valid cells
                        if(x >= 0 && x <= m-1 && y >= 0 && y <= n-1) {
                            sum += img[x][y];
                            count += 1;
                        }
                    }
                }
                smoothen_image[i][j] = (sum / count);
            }
        }

        return smoothen_image;
    }
};