class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> adj;
        vector<double> result(n, 0);
        
        // Creating adjacency list/map
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];    // Probability of path b/w u and v
            adj[u].push_back({v, p});
            adj[v].push_back({u, p});   // Since graph is undirected
        }
        
        priority_queue<pair<double, int>> pq; // Max Heap
        result[start_node] = 1.0;       // Max prob. of going from start node to start node is 1
        pq.push({1.0, start_node});     // Pushing start node and its probability into max heap as {prob, start_node}
        
        // Iterate until map heap is empty
        while(!pq.empty()) {
            int currNode = pq.top().second;
            double currProb = pq.top().first;
            pq.pop();
            
            for(auto &temp: adj[currNode]) {
                int adjNode = temp.first;
                double adjProb = temp.second;
                
                if(currProb*adjProb > result[adjNode]) {
                    result[adjNode] = currProb*adjProb;    // Update probability in result vector
                    pq.push({currProb*adjProb, adjNode});   // Push node to max heap
                }
            }
        }
        
        return result[end_node];
    }
};