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
    // Approach 1 (Recursive Way)
    // T.C. = O(n)
    // S.C. = O(n)
    TreeNode* prev = NULL;
    void flatten1(TreeNode* root) {
        if(root == NULL)
            return;
        
        flatten1(root->right);
        flatten1(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }

    void flatten(TreeNode* root) {
        // Approach 1 
        return flatten1(root);
    }
};