class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> mergedIntervals;

        // Sorting intervals
        sort(intervals.begin(), intervals.end());

        for(int i = 0; i < n; i++) {
            // If it is first pair or if its interval do not overlap with the 
            // last pair in mergedIntervals
            if(mergedIntervals.empty() || intervals[i][0] > mergedIntervals.back()[1]) {
                // add this pair in merged interval
                mergedIntervals.push_back(intervals[i]);
            }

            // If the current pair can be merged with last pair in merged interval
            if(intervals[i][0] <= mergedIntervals.back()[1]) {
                // Update the ending point of merged pair
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], intervals[i][1]);
            }
        }

        return mergedIntervals;
    }
};