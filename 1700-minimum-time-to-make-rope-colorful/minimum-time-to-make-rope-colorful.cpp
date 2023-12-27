class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int minTime = 0;
        int sum = 0;
        int maxSum = 0;
        int n = colors.size();
        for(int i = 0; i < n; i++) {
            sum += neededTime[i];
        }
        for(int i = 0; i < n; i++) {
            int mx = neededTime[i];
            if(i < n-1 && colors[i] == colors[i+1]) {
                while(i < n-1 && colors[i] == colors[i+1]) {
                    mx = max(mx, neededTime[i+1]);
                    i++;
                }
            }
            // cout << "mx= " << mx << endl;
            maxSum += mx;
        }
        // cout << "sum = " << sum << endl;
        // cout << "maxSum= " << maxSum << endl;
        minTime = sum - maxSum;
        return minTime;
    }
};