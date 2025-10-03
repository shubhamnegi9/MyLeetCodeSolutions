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
    // Using recursive approach
    // T.C. = O(h)
    // S.C. = O(h) recursive stack space
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        
        int currVal = root->val;

        // Both p and q are present in right subtree
        if(p->val > currVal && q->val > currVal) {
            return lowestCommonAncestor1(root->right, p, q);
        }

        // Both p and q are present in left subtree
        if(p->val < currVal && q->val < currVal) {
            return lowestCommonAncestor1(root->left, p, q);
        }

        // root is LCA
        return root;
    }

    // Using iterative approach
    // T.C. = O(h)
    // S.C. = O(1)
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        
        while(root != NULL) {
            int currVal = root->val;

            // Both p and q are present in right subtree
            if(p->val > currVal && q->val > currVal) {
                root = root->right;
            }

            // Both p and q are present in left subtree
            else if(p->val < currVal && q->val < currVal) {
                root = root->left;
            }

            // Otherwise, current node is the split point => LCA
            else {
                // root is LCA
                return root;
            }
        }

        return NULL;
    }

    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Using recursive approach
        // return lowestCommonAncestor1(root, p, q);

        // Using iterative approach
        return lowestCommonAncestor2(root, p, q);

    }
};