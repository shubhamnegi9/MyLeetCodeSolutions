class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int minTime = 0;
        int n = colors.size();
        // Taking 2 pointers 'start' and 'end'
        int start = 0;
        int end = 0;
        while(start < n && end < n) {
            // groupMax for tracking maximum time in same consecutive group color boloons
            int groupMax = neededTime[start];
            // groupSum for finding total time in same consecutive group color boloons
            int groupSum = 0;
            // Iterating in same consecutive group color boloons
            while(end < n && colors[start] == colors[end]) {
                groupSum += neededTime[end];
                groupMax = max(groupMax, neededTime[end]);
                end++;
            }
            // Min time required to remove same consecutive group color boloons
            minTime += (groupSum - groupMax);
            // Updating start to next consecutive group color boloons
            start = end;
        }
        return minTime;
    }
};