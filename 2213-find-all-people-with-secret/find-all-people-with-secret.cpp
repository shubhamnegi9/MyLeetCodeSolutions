class Solution {
public:
    typedef pair<int, int> P;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // Unordered map for storing in increasing order of meeting times
        map<int, vector<P>> meetingTimes;

        for(vector<int> meeting: meetings) {
            int firstPerson = meeting[0];
            int secondPerson = meeting[1];
            int time = meeting[2];

            // Storing meetings in increasing order of time as key
            meetingTimes[time].push_back({firstPerson, secondPerson});
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
                adj[firstPerson].push_back(secondPerson);
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
                int person = q.front();
                q.pop();

                for(auto &nextPerson: adj[person]) {
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
};