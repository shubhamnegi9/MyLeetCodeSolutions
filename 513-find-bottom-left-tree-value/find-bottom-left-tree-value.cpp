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
    int maxDepth;
    int bottomLeftVal;

    // Using DFS
    void findUsingDFS(TreeNode* root, int depth) {
        // Base Case
        if(root == NULL)
            return;

        // Updating maxDepth of Tree
        if(depth > maxDepth) {
            maxDepth = depth;
            // First value at maxDepth will be bottomLeftVal
            bottomLeftVal = root -> val;    
        }
        // Calling recursively for left and right subtree by increasing depth
        findUsingDFS(root->left, depth+1);
        findUsingDFS(root->right, depth+1);
    }

    // Using BFS
    void findUsingBFS(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            // Updating bottomLeftVal to value of node popped
            bottomLeftVal = node->val;

            // Pusing right child in queue first and then left child
            // so that the last node in queue will be bottom left tree node
            // in the last row
            if(node->right)
                q.push(node->right);
            if(node->left)
                q.push(node->left);
        }
    }

    // Using Level Wise BFS
    void findUsingBFSLevelWise(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            
            int n = q.size();   // Number of nodes at current level
            // Process all nodes at once in current level
            while(n--) {
                TreeNode* node = q.front();
                q.pop();
                // Updating bottomLeftVal to value of node popped
                bottomLeftVal = node->val;

                // Pusing right child in queue first and then left child
                // so that the last node in queue will be bottom left tree node
                // in the last row
                if(node->right)
                    q.push(node->right);
                if(node->left)
                    q.push(node->left);
            }
        }
    }

    int findBottomLeftValue(TreeNode* root) {

        // Using DFS
        // maxDepth = -1;
        // findUsingDFS(root, 0);
        // return bottomLeftVal;

        // Using BFS
        findUsingBFS(root);
        return bottomLeftVal;

        // Using Level Wise BFS
        findUsingBFSLevelWise(root);
        return bottomLeftVal;
    }
};