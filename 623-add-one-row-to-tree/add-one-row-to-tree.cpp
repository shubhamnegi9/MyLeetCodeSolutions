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

    TreeNode* addToRow(TreeNode* root, int val, int depth, int currDepth) {
        // Base Case
        if(root == NULL)
            return NULL;
        
        // This is the depth where new row to be added
        if(currDepth == depth-1) {
            // Save left and right subtrees of current node in temp 
            TreeNode* leftTemp = root->left;
            TreeNode* rightTemp = root->right;

            // Create 2 new nodes with value 'val' and make it as left and right subtree of current node resp. 
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            // Make saved left and right subtrees as left and right subtrees of new nodes resp.
            root->left->left = leftTemp;
            root->right->right = rightTemp;
            return root;
        }

        // Otherwise call for left and right subtrees with increased depth, and attach the new subtrees created as left and right subtrees of current node
        root->left = addToRow(root->left, val, depth, currDepth+1);
        root->right = addToRow(root->right, val, depth, currDepth+1);

        // Return root node
        return root;
    }

    // Using DFS
    TreeNode* addOneRowUsingDFS(TreeNode* root, int val, int depth) {
        // Root Node
        if(depth == 1) {
            // Create a new node and add original tree to its left and return this node
            TreeNode* newNode = new TreeNode(val);
            newNode -> left = root;
            return newNode;
        }

        // Otherwise traverse in tree and add the node row at particular depth 
        return addToRow(root, val, depth, 1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        return addOneRowUsingDFS(root, val, depth);
    }
};