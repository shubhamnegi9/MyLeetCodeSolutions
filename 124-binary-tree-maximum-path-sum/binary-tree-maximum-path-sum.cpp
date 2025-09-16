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
    int maxPathDown(TreeNode* node, int &maxi) {
        if(node == NULL)
            return 0;
        
        int leftSum = max(0, maxPathDown(node->left, maxi));
        int rightSum = max(0, maxPathDown(node->right, maxi));

        maxi = max(maxi, leftSum + rightSum + (node->val));

        return (node->val) + max(leftSum, rightSum);
    }

    // T.C. = O(n)
    // S.C. =  O(1) extra space, O(h) recursive stack space
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }
};