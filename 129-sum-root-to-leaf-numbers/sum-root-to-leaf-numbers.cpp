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
    int solve(TreeNode* root, int value) {
        // Base case
        if(root == NULL)
            return 0;
        
        // Appending current node value to previous node value
        value = (value*10) + root->val;

        // If leaf node then return the value
        if(root -> left == NULL && root -> right == NULL) {
            return value;
        }

        int left = solve(root->left, value);
        int right = solve(root->right, value);

        return left+right;
    }
    
    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
};