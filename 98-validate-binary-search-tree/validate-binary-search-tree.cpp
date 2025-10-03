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
    bool isValidBST(TreeNode* root, long minVal, long maxVal) {
        // If NULL node, then it is BST
        if(root == NULL)
            return true;
        
        // If node's value is out of range, then return false
        if(root->val <= minVal || root->val >= maxVal) 
            return false;

        // For left subtree, root->val is maxVal
        // For right subtrree, root->val is minVal
        return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
    }

    // T.C. = O(n)
    // S.C. = O(h)
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
};