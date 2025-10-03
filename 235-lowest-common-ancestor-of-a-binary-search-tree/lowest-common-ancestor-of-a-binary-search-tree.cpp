/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        
        int currVal = root->val;

        // Both p and q are present in right subtree
        if(p->val > currVal && q->val > currVal) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // Both p and q are present in left subtree
        if(p->val < currVal && q->val < currVal) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // root is LCA
        return root;
    }
};