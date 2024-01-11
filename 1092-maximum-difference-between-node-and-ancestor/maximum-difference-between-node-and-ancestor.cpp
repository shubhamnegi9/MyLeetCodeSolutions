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
    int maxDiff;

    void findMaxDiffUtil(TreeNode* root, TreeNode* child) {
        if(root == NULL || child == NULL) {
            return;
        }

        maxDiff = max(maxDiff, abs(root->val - child->val));
        findMaxDiffUtil(root, child->left);
        findMaxDiffUtil(root, child->right);
    }

    void findMaxDiff(TreeNode* root) {
        if(root == NULL)
            return;
        
        findMaxDiffUtil(root, root-> left);
        findMaxDiffUtil(root, root-> right);

        findMaxDiff(root->left);
        findMaxDiff(root->right);
    }

    int findMaxDiffOptimal(TreeNode* root, int maxVal, int minVal) {
        // On reaching leaf node for a particular path, 
        // returning maxDiff for that path
        if(root == NULL) {
            return abs(maxVal - minVal);
        }

        // Updating maxVal and minVal at every node
        maxVal = max(maxVal, root->val);
        minVal = min(minVal, root->val);

        // Finding maxDiff from left path
        int l = findMaxDiffOptimal(root->left, maxVal, minVal);
        // Fining maxDiff from right path
        int r = findMaxDiffOptimal(root->right, maxVal, minVal);

        // Returning maximum difference out of left and right paths
        return max(l, r);
    }

    int maxAncestorDiff(TreeNode* root) {
        // Brute Force Approach:
        /*maxDiff = -1;
        findMaxDiff(root);
        return maxDiff;*/

        // Optimal Approach:
        return findMaxDiffOptimal(root, root->val, root->val);
    }
};