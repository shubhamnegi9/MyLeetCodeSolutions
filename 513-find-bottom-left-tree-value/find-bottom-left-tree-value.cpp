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



    int findBottomLeftValue(TreeNode* root) {

        // Using DFS
        maxDepth = -1;
        findUsingDFS(root, 0);
        return bottomLeftVal;
    }
};