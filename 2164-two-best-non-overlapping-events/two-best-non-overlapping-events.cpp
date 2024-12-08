class Solution {
public:
    int n;
    // Brute Force Approach - TLE
    // T.C. = O(nlogn) + O(n^2)
    // S.C : O(1)
    bool isOverlapping(int start1, int end1, int start2, int end2) {
        // cout << "start1 = " << start1 << endl;
        // cout << "end1 = " << end1 << endl;
        // cout << "start2 = " << start2 << endl;
        // cout << "end2 = " << end2 << endl;
        return ((start1 <= end2) && (start2 <= end1));    
    }
    
    int maxTwoEvents1(vector<vector<int>>& events) {
        // Sorting the intervals based on start times
        sort(events.begin(), events.end());
        
        n = events.size();
        int maxSum = 0;
        
        for(int i = 0; i < n; i++) {
            int sum = events[i][2];
            if(i < n-1) {
                for(int j = i+1; j < n; j++) {
                    if(!isOverlapping(events[i][0], events[i][1], events[j][0], events[j][1])) {
                        // We have not done sum += events[j][2] as we can choose at most two non-overlapping events
                        maxSum = max(maxSum, sum + events[j][2]);   
                    }
                }
            }   
            // maxSum is calculated here again for single interval 
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
    
    // Using Recursion - TLE
    // Finding upper_bound of endTime
    int binarySearch(vector<vector<int>>& events, int endTime) {
        int l = 0;
        int r = n-1;
        int result = n;
            
        while(l <= r) {
            int mid = l+(r-l)/2;
            
             // Find next interval index whose start time is greater than endTime of previous interval 
            if(events[mid][0] > endTime) { 
                result = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        
        return result;
    }
    
    int solve(vector<vector<int>>& events, int i, int count) {
        
        // Base case
        if(count == 2 || i >= n) {
            return 0;
        }
        
        int nextNonOverlappingEventIndex = binarySearch(events, events[i][1]);
        int take = events[i][2] + solve(events, nextNonOverlappingEventIndex, count+1);
        int notTake = solve(events, i+1, count);
        return max(take, notTake);
    }
    
    int maxTwoEvents2(vector<vector<int>>& events) {
        n = events.size();
        
        // Sorting the intervals based on start times
        sort(events.begin(), events.end());
        
        return solve(events, 0, 0);
    }
    
    // Using Recursion + Memoization   
    // T.C : O(n * logn, After memoizing, we will visit at max n states and for binarysearch it will take log(n))
    // S.C : O(n*3) ~= O(n)
    int solveMemo(vector<vector<int>>& events, int i, int count, vector<vector<int>>& dp) {
        
        // Base case
        if(count == 2 || i >= n) {
            return 0;
        }
        
        if(dp[i][count] != -1) {
            return dp[i][count];
        }
        
        int nextNonOverlappingEventIndex = binarySearch(events, events[i][1]);
        int take = events[i][2] + solveMemo(events, nextNonOverlappingEventIndex, count+1, dp);
        int notTake = solveMemo(events, i+1, count, dp);
        return dp[i][count] = max(take, notTake);
    }
    
    int maxTwoEvents3(vector<vector<int>>& events) {
        n = events.size();
        
        // Sorting the intervals based on start times
        sort(events.begin(), events.end());
        
        // Taking 2-D dp vector as 2 variables 'i' and 'count' are changing in recursive function
        // 'i' ranges from 0 to n-1 and 'count' ranges from 0 to 1
        vector<vector<int>> dp(n, vector<int>(2, -1));  
        return solveMemo(events, 0, 0, dp);
    }
    
    int maxTwoEvents(vector<vector<int>>& events) {
        // Brute Force Approach - TLE
        // return maxTwoEvents1(events);
        
        // Using Recursion - TLE
        // return maxTwoEvents2(events);
        
        // Using Recursion + Memoization
        return maxTwoEvents3(events);
    }
};