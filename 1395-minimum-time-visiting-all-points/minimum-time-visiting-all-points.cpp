class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int minTime = 0;
        for(auto p = points.begin(); p != points.end()-1; p++) {
            int time = 0;
            vector<int> currPoint = *p;
            vector<int> nextPoint = *(p+1);
            int currX = currPoint[0], currY = currPoint[1], targetX = nextPoint[0], targetY = nextPoint[1];

            minTime += max(abs(targetX - currX), abs(targetY - currY));
        }
        // cout << " minTime= " << minTime << endl;
        return minTime;
    }
};