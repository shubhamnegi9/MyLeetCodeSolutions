class Solution {
public:
    
    vector<vector<int>> merge1(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> mergedIntervals;

        for(int i = 0; i < n; i++) {
            if(mergedIntervals.empty() || intervals[i][0] > mergedIntervals.back()[1]) {
                int start = intervals[i][0];
                int end = intervals[i][1];

                if(i < n-1) {
                    for(int j = i+1; j < n; j++) {
                        if(intervals[j][0] <= end) {
                            end = max(end, intervals[j][1]);
                        } else {
                            break;
                        }
                    }
                }
                mergedIntervals.push_back({start, end});
            }
        }

        return mergedIntervals;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        return merge1(intervals);
    }
};