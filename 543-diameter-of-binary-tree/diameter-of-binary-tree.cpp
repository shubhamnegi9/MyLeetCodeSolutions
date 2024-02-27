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
    int findDiameter(TreeNode* root, int& res) {
        // Base Case
        if(root == NULL)
            return 0;
        
        // Length of longest path in left subtree
        int l = findDiameter(root->left, res);
        // Length of longest path in right subtree
        int r = findDiameter(root->right, res);
        // Diameter at current node 
        res = max(res, l+r);

        // Diameter returned to parent node
        return 1+max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN;
        findDiameter(root, res);
        return res;
    }
};