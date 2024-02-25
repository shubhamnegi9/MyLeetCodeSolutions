class Solution {
public:
    typedef pair<int, int> P;

    // Approach 1 : Using ordered map of meeting times + BFS
    /*  Time Complexity = O(m) for iterating in meetings vector * O(V+E) for BFS
                        = O(m) * O(m+n)
                        (m = number of meetings, n = number of persons)
        Space Complexity = O(m+n) for queue in BFS + O(m) for meetingTimes map + O(n) for knowsSecret + O(n) for visited set
                         = O(m+n) overall  
    */
    vector<int> findAllPeopleUtil1(int n, vector<vector<int>>& meetings, int firstPerson) {
       // Ordered map for storing in increasing order of meeting times
        map<int, vector<P>> meetingTimes;   // time -> [[firstPerson, secondPerson], ....], ...

        for(vector<int> meeting: meetings) {
            int firstPerson = meeting[0];
            int secondPerson = meeting[1];
            int time = meeting[2];

            // Storing meetings in increasing order of time as key
            meetingTimes[time].push_back({firstPerson, secondPerson});  // 3 -> [[3, 1], [0, 3]], 2 -> [1, 2]... 
        }

        vector<bool> knowsSecret(n, false);
        // Initially Person 0 and firstPerson knows secret
        knowsSecret[0] = true;
        knowsSecret[firstPerson] = true;

        for(auto &it: meetingTimes) {
            int time = it.first;
            vector<P> meets = it.second;

            unordered_map<int, vector<int>> adj;    // Adjacency List
            unordered_set<int> visited;             // Set for visited nodes in queue
            queue<int> q;                           // Queue for BFS traversal

            for(auto &[firstPerson, secondPerson]: meets) {
                // Adding to adjacency list
                // Both persons can share secret to each other
                adj[firstPerson].push_back(secondPerson);   // 3 -> [1, 0], 1 -> [3, 2], 2 -> [1]... 
                adj[secondPerson].push_back(firstPerson);

                // If firstPerson knows secret and it is not added in queue the add it 
                // so that we start spreading secret from it
                if(knowsSecret[firstPerson] && visited.find(firstPerson) == visited.end()) {    
                    q.push(firstPerson);
                    visited.insert(firstPerson);
                }
                // If secondPerson knows secret and it is not added in queue the add it 
                // so that we start spreading secret from it
                if(knowsSecret[secondPerson] && visited.find(secondPerson) == visited.end()) {
                    q.push(secondPerson);
                    visited.insert(secondPerson);
                }
            }

            
            // Now we have the adjacency list of the meetings in sorted order of time
            // Now spread the secret using BFS
            while(!q.empty()) {
                int person = q.front();  // Current person who knows the secret and will spread it further
                q.pop();

                for(auto &nextPerson: adj[person]) {
                    // Spread secret to nextPerson only when he does not already know the secret
                    if(!knowsSecret[nextPerson]) {
                        knowsSecret[nextPerson] = true; // Secret is spread to nextPerson
                        q.push(nextPerson); // Adding nextPerson to queue so we can spread secret further from it
                    }
                }
            }
        }

        vector<int> result;
        // Finally iterate in knowsSecret vector and check who all knows the secret
        for(int i = 0; i < n; i++) {
            if(knowsSecret[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
    
    // Approach 2 : Without using ordered map of meeting times + BFS
    /*
        In approach 1, we were first creating ordered map of meeting times and then creating 
        the adjacency list from it and doing BFS.
        In this approach, we will directly create the adjacency list from meetings vector 
        and do BFS.
    */
    vector<int> findAllPeopleUtil2(int n, vector<vector<int>>& meetings, int firstPerson) {

        // Adjacency list for doing BFS
        unordered_map<int, vector<P>> adj;  // firstPerson -> [[secondPerson, time], ...], ...

        // Filling adjacency list
        for(vector<int> meeting: meetings) {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time = meeting[2];

            // Both persons can share secret to each other
            adj[person1].push_back({person2, time});
            adj[person2].push_back({person1, time});
        }

        // Vector to store the minimum times when each person knows secret
        vector<int> timeToKnowSecret(n, INT_MAX);
        timeToKnowSecret[0] = 0;            // Person 0 knows the secret at time 0
        timeToKnowSecret[firstPerson] = 0;  // firstPerson knows the secret at time 0

        // Queue for BFS
        queue<P> q; // Stores pair of {person, time}
        // Adding person0 and firstPerson to queue so that we can start spreading secret from them 
        q.push({0, 0});    
        q.push({firstPerson, 0});

        // Now spread the secret using BFS
        while(!q.empty()) {
            // person: Current person who knows the secret and will spread it further
            // time: Time when the current person knows the secret
            auto [person, time] = q.front();    
            q.pop();

            for(auto &ngbr: adj[person]) {
                int nextPerson = ngbr.first;    // Next person to whom secret needs to be spread
                int meetTime = ngbr.second;     // Time when the next person knows the secret

                // Spread secret to nextPerson only when the time when the next person knows the secret
                // is greater than or equal to time when the current person knows the secret, as well as
                // it is less than the minimum time when the nextPerson knows the secret
                if(meetTime >= time && meetTime < timeToKnowSecret[nextPerson]) {
                    timeToKnowSecret[nextPerson] = meetTime;    // Update the minimum time when next person knows the secret
                    q.push({nextPerson, meetTime});        // Adding nextPerson to queue so we can spread secret further from it
                }
            }
        }

        vector<int> result;
        // Finally iterate in timeToKnowSecret vector and check who all knows the secret
        for(int i = 0; i < n; i++) {
            if(timeToKnowSecret[i] != INT_MAX) {
                result.push_back(i);
            }
        }

        return result;

    }

    // Approach 3: Without using ordered map of meeting times + DFS

    void DFS(int person, int time, unordered_map<int, vector<P>>& adj, vector<int>& timeToKnowSecret) {

        for(auto &ngbr: adj[person]) {
            int nextPerson = ngbr.first;    // Next person to whom secret needs to be spread
            int meetTime = ngbr.second;     // Time when the next person knows the secret

            // Spread secret to nextPerson only when the time when the next person knows the secret
            // is greater than or equal to time when the current person knows the secret, as well as
            // it is less than the minimum time when the nextPerson knows the secret
            if(meetTime >= time && meetTime < timeToKnowSecret[nextPerson]) {
                timeToKnowSecret[nextPerson] = meetTime;    // Update the minimum time when next person knows the secret
                DFS(nextPerson, meetTime, adj, timeToKnowSecret);      // Calling DFS for nextPerson so we can spread secret further from it
            }
        }
    }

    vector<int> findAllPeopleUtil3(int n, vector<vector<int>>& meetings, int firstPerson) {

        // Adjacency list for doing BFS
        unordered_map<int, vector<P>> adj;  // firstPerson -> [[secondPerson, time], ...], ...

        // Filling adjacency list
        for(vector<int> meeting: meetings) {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time = meeting[2];

            // Both persons can share secret to each other
            adj[person1].push_back({person2, time});
            adj[person2].push_back({person1, time});
        }

        // Vector to store the minimum times when each person knows secret
        vector<int> timeToKnowSecret(n, INT_MAX);
        timeToKnowSecret[0] = 0;            // Person 0 knows the secret at time 0
        timeToKnowSecret[firstPerson] = 0;  // firstPerson knows the secret at time 0

        // Now spread the secret using DFS
        // Initially person 0 and firstPerson knows the secret. So start spreading from them.
        DFS(0, 0, adj, timeToKnowSecret);
        DFS(firstPerson, 0, adj, timeToKnowSecret);

        vector<int> result;
        // Finally iterate in timeToKnowSecret vector and check who all knows the secret
        for(int i = 0; i < n; i++) {
            if(timeToKnowSecret[i] != INT_MAX) {
                result.push_back(i);
            }
        }

        return result;

    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        // Approach 1
        // return findAllPeopleUtil1(n, meetings, firstPerson);

        // Approach 2
        // return findAllPeopleUtil2(n, meetings, firstPerson);

        // Approach 3
        return findAllPeopleUtil3(n, meetings, firstPerson);
    }
};