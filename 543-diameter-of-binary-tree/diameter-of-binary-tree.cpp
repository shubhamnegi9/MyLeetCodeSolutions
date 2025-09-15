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
    // T.C. = O(n^2)
    // S.C. = O(1) extra space, O(h) recursive stack space
    void diameterOfBinaryTree1(TreeNode* root, int &maxi) {
        if(root == NULL)
            return;
        
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        maxi = max(maxi, lh+rh);
        diameterOfBinaryTree1(root->left, maxi);
        diameterOfBinaryTree1(root->right, maxi);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        // Brute Force Approach
        diameterOfBinaryTree1(root, maxi);
        return maxi;
    }
};