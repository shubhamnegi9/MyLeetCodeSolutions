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
    
    // Using DFS
    bool isSameTreeDFS(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;    // Same Tree
        
        if(p == NULL || q == NULL) {    // Same as (p == NULL and q != NULL) || (p != NULL and q == NULL)
            return false;   // Not Same Tree
        }

        // Checking for values at nodes
        if(p->val != q->val) {
            return false;
        }

        // Checking for equalness of left subtree as well as right subtreee using recurison
        return isSameTreeDFS(p->left, q->left) && isSameTreeDFS(p->right, q->right);

    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Using DFS
        return isSameTreeDFS(p, q);
    }
};