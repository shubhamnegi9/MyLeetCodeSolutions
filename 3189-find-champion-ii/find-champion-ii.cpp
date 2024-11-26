class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        
        for(vector<int>& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            
            // Since directed edge is from u to v, so indegree of v will increase by 1
            indegree[v]++;
        }
        
        int champion = -1;
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                count++;
                champion = i;
                if(count > 1)
                    return -1;
            }
        }
        return champion;
    }
};