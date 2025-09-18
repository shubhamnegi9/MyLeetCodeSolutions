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
    bool isSymmetricHelper(TreeNode* leftNode, TreeNode* rightNode) {
        // If leftNode and rightNode both are null, then only return true, else if any one of them is false,
        // then return false
        if(leftNode == NULL || rightNode == NULL)
            return leftNode == rightNode;
        
        if(leftNode->val != rightNode->val) {
            return false;
        }

        // Simulatenous preorder and reverse preorder traversal on left and right subtree
        return isSymmetricHelper(leftNode->left, rightNode->right) && 
               isSymmetricHelper(leftNode->right, rightNode->left);          
    }

    // T.C. = O(n)
    // S.C. = O(h)
    bool isSymmetric(TreeNode* root) {
        return (root == NULL || isSymmetricHelper(root->left, root->right));
    }
};