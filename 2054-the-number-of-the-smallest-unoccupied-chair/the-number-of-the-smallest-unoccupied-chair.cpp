class Solution {
public:
    
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(n)
    int smallestChair1(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> chairs(n, -1);
        
        int targetFriendArrivalTime = times[targetFriend][0];
        
        sort(times.begin(), times.end());
        
        for(vector<int> &time: times) {
            int arrival = time[0];
            int depart = time[1];
            
            for(int i = 0; i < n; i++) {
                
                if(arrival >= chairs[i]) {
                    chairs[i] = depart;
                    if(arrival == targetFriendArrivalTime) {
                        return i;
                    }
                    break;
                }
            }
        }
        
        return -1;
        
    }
    
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        return smallestChair1(times, targetFriend);
    }
};