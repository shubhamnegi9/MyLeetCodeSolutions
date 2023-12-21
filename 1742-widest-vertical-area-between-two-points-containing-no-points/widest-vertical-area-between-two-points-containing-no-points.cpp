class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> s;
        for(int i = 0; i < points.size(); i++) {
            s.insert(points[i][0]);
        }
        vector<int> xPoints;
        for(auto ele: s) {
            xPoints.push_back(ele);
        }
        int maxWidth = 0;
        for(int i = 1; i < xPoints.size(); i++) {
            int width = xPoints[i] - xPoints[i-1];
            if(width > maxWidth) 
                maxWidth = width;
        }

        return maxWidth;
    }
};