class Solution {
public:
    // Brute Force Approach
    // T.C. = O(nlogn) + O(2*n)
    // S.C. = O(n)
    vector<vector<int>> merge1(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> mergedIntervals;
        
        for(int i = 0; i < n; i++) {
            if(!mergedIntervals.empty() && intervals[i][0] <= mergedIntervals.back()[1]) {
                continue;
            }
            
            int startTime = intervals[i][0];
            int endTime = intervals[i][1];
            
            for(int j = i+1; j < n; j++) {
                if(intervals[j][0] <= endTime) {
                    endTime = max(endTime, intervals[j][1]);
                }
                else {
                    break;
                }
            }
            mergedIntervals.push_back({startTime, endTime});
        }
        
        return mergedIntervals;
    }
    
    // Optimal Approach
    // T.C. = O(nlogn) + O(n)
    // S.C. = O(n)
    vector<vector<int>> merge2(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> mergedIntervals;
        
        for(int i = 0; i < n; i++) {
            if(mergedIntervals.empty() || intervals[i][0] > mergedIntervals.back()[1]) {
                mergedIntervals.push_back(intervals[i]);
            } 
            else if(intervals[i][0] <= mergedIntervals.back()[1]){
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], intervals[i][1]);
            }
        }
        
        return mergedIntervals;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Brute Force Approach
        // return merge1(intervals);
        
        // Optimal Approach
        return merge2(intervals);
    }
};