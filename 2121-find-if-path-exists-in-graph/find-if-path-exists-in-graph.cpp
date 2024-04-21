class Solution {
public:

    bool validPathUsingDFS(unordered_map<int, vector<int>> &adj, int source, int destination, vector<bool> &visited) {
        // Valid path
        if(source == destination)
            return true;
        
        // If current source node is already visited, retrun false 
        if(visited[source]) {
            return false;
        }

        // Mark current source node as visited
        visited[source] = true;

        // Calling DFS using neighbour nodes and checking if valid path found
        for(auto &ngbr: adj[source]) {
            if(validPathUsingDFS(adj, ngbr, destination, visited))
                return true;
        }

        // Valid path cannot be found if reached till here
        return false;
    }

    bool validPathUsingBFS(unordered_map<int, vector<int>> &adj, int source, int destination, vector<bool> &visited) {
        
        queue<int> q;
        // Push current source node in queue and mark it as visited
        q.push(source);
        visited[source] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            // If current node is destination node, valid path is found
            if(node == destination)
                return true;

            // Checking for neighbour nodes and pushing them to queue if not visited
            for(auto &ngbr: adj[node]) {
                if(!visited[ngbr]) {
                    q.push(ngbr);
                    visited[ngbr] = true;
                }
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Adjacency list
        unordered_map<int, vector<int>> adj;

        // Creating adjacency list
        for(vector<int> &edge : edges) {
            int u = edge[0];     // source
            int v = edge[1];     // destination
            // bidirectional graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Vector to store visited nodes
        vector<bool> visited(n, false);

        // Using DFS
        // return validPathUsingDFS(adj, source, destination, visited);

        // Using BFS
        return validPathUsingBFS(adj, source, destination, visited);
    }
};