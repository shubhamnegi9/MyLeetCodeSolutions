/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void makeGraph(TreeNode* root, int parent, unordered_map<int, vector<int>>& adj) {
        // Base case
        if(root == NULL)
            return;
        
        // Pushing parent node to adjacency list of curernt node
        if(parent != -1) {
            adj[root->val].push_back(parent);
        }

        // Pushing left node to adjacency list of curernt node
        if(root->left) {
            adj[root->val].push_back(root->left->val);
        }
        // Pushing right node to adjacency list of curernt node
        if(root->right) {
            adj[root->val].push_back(root->right->val);
        }

        // recursive call to left child
        // parent node for left child will be current node
        makeGraph(root->left, root->val, adj);

        // recursive call to right child
        // parent node for right child will be current node
        makeGraph(root->right, root->val, adj);
    }

    int amountOfTimeUsingBFS(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        // Creating adjacency list
        makeGraph(root, -1, adj);

        // BFS traversal
        queue<int> q;
        unordered_set<int> visited;
        q.push(start);
        visited.insert(start);

        int minutes = 0;
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                int curr = q.front();
                q.pop();
                // Pushing the neighbours of current node in queue if they are 
                // not visited and marking them as visited
                for(int neighbour: adj[curr]) {
                    if(visited.find(neighbour) == visited.end()) {
                        q.push(neighbour);
                        visited.insert(neighbour);
                    }
                }
            }
            // Increasing time once all neighbours are visited
            minutes++;
        }

        return (minutes-1);
    }

    int amountOfTime(TreeNode* root, int start) {
        return amountOfTimeUsingBFS(root, start);
    }
};