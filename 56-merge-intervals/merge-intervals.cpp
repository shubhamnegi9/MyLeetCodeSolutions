class Solution {
public:
    // Brute Force Approach
    // T.C. = O(nlogn) + O(n^2)
    // S.C. = O(1) for solving problem
    vector<vector<int>> merge1(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> result;

        // Sort the intervals based on start times
        sort(intervals.begin(), intervals.end());

        for(int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            // Current interval is already present in merged interval, so skip it
            if(!result.empty() && end <= result.back()[1]) {
                continue;
            }

            for(int j = i+1; j < n; j++) {
                if(intervals[j][0] <= end) {
                    // Current interval can be added to merged interval
                    end = max(end, intervals[j][1]);
                } else {
                    // Current interval cannot be added to merged interval. Also skip further intervals
                    break;
                }
            }

            result.push_back({start, end});
        }

        return  result;
    }

    // Optimal Approach
    // T.C. = O(nlogn) + O(n)
    // S.C. = O(1) for solving problem
    vector<vector<int>> merge2(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> result;

        // Sort the intervals based on start times
        sort(intervals.begin(), intervals.end());

        for(int i = 0; i < n; i++) {
            // Current interval cannot be merged to previous interval
            if(result.empty() || (!result.empty() && intervals[i][0] > result.back()[1])) {
                result.push_back(intervals[i]);
            } else {
                // Current interval can be merged to previous interval
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
        }

        return result;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Brute Force Approach
        // return merge1(intervals);

        // Optimal Approach
        return merge2(intervals);
    }
};