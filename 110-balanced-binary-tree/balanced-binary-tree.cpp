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
    // S.C. = O(n)
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

    int dfsHeight(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int lh = dfsHeight(root->left);
        if(lh == -1)
            return -1;
        int rh = dfsHeight(root->right);
        if(rh == -1)
            return -1;
        if(abs(lh - rh) > 1)
            return -1;
        
        return 1 + max(lh, rh);
    }

    // Optimal Approach
    // T.C = O(n)
    // S.C. = O(n)
    bool isBalanced2(TreeNode* root) {
        return dfsHeight(root) == -1 ? false : true;
    }

    bool isBalanced(TreeNode* root) {
        // Brute Force Approach
        // return isBalanced1(root);

        // Optimal Approach
        return isBalanced2(root);
    }
};