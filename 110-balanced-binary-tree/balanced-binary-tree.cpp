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
    int findHeight(TreeNode* root) {
        if(root == NULL)
            return 0;
        return 1 + max(findHeight(root->left), findHeight(root->right));
    }

    // Brute Force Approach
    bool isBalanced1(TreeNode* root) {
        // If node is null, then tree is balanced
        if(root == NULL)
            return true;
        
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);

        if(abs(lh-rh) > 1) 
            return false;
        
        // Checking if each node is balanced by calling recursive function
        bool isLeftBalanced = isBalanced1(root->left);
        bool isRightBalanced = isBalanced1(root->right);

        if(!isLeftBalanced || !isRightBalanced)
            return false;
        
        return true;
    }

    bool isBalanced(TreeNode* root) {
        // Brute Force Approach
        return isBalanced1(root);

    }
};