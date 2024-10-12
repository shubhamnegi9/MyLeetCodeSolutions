class Solution {
public:
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(n)
    int minGroups1(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> groups(n, -1);
        
        sort(intervals.begin(), intervals.end());
        
        int count = 0;
        for(vector<int> &interval: intervals) {
            int start = interval[0];
            int end = interval[1];
            
            for(int i = 0; i < n; i++) {
                if(start > groups[i]) {
                    if(groups[i] == -1) {
                        count++;
                    }
                    groups[i] = end;
                    break;
                }
            }
        }
        return count;
    }
    
    // Optimnal Approach
    // T.C. = O(nlogn)
    // S.C. = O(n)
    int minGroups2(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(vector<int> &interval: intervals) {
            int start = interval[0];
            int end = interval[1];
            
            if(!pq.empty() && start > pq.top()) {
                pq.pop();
            }
            pq.push(end);
        }
        
        return pq.size();
    }
    
    int minGroups(vector<vector<int>>& intervals) {
        // Brute Force Approach
        // return minGroups1(intervals);
        
        // Optimnal Approach
        return minGroups2(intervals);
    }
};