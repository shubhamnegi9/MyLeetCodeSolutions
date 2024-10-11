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
    
    // Optimal Approach
    // T.C. = O(nlogn)
    // S.C. = O(n)
    typedef pair<int, int> P;
    int smallestChair2(vector<vector<int>>& times, int targetFriend) {
    
        // Min Heap for occupied chairs
        priority_queue<P, vector<P>, greater<P>> occupied;
        // Min Heap for free chairs
        priority_queue<int, vector<int>, greater<int>> free;
        
        int chair = 0;
        
        int targetFriendArrivalTime = times[targetFriend][0];
        
        sort(times.begin(), times.end());
        
        for(vector<int> &time: times) {
            int arrival = time[0];
            int depart = time[1];
            
            while(!occupied.empty() && arrival >= occupied.top().first) {
                free.push(occupied.top().second);
                occupied.pop();
            }
            
            if(free.empty()) {
                if(arrival == targetFriendArrivalTime) {
                    return chair;
                }
                occupied.push({depart, chair});
                chair++;
            } else {
                int freeChair = free.top();
                free.pop();
                if(arrival == targetFriendArrivalTime) {
                    return freeChair;
                }
                occupied.push({depart, freeChair});
            }
        }
        
        return -1;
        
    }
    
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
         // Brute Force Approach
        // return smallestChair1(times, targetFriend);
        
        // Optimal Approach
        return smallestChair2(times, targetFriend);
    }
};