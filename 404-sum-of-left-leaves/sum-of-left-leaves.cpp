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

    // Approach 1 : Using Parent Pointer
    int solve1(TreeNode* curr, TreeNode* parent) {

        // NULL node 
        if(curr == NULL)
            return 0;
        
        // Leaf Node
        if(curr->left == NULL && curr->right == NULL) {
            // If parent node is not null and current node is left child of parent
            if(parent != NULL && parent->left == curr) {
                return curr->val;
            }
        }

        // Making recursive call to left subtree for finding sum of left leaves
        int left = solve1(curr->left, curr);    // Current node will become parent node
        // Making recursive call to right subtree for finding sum of left leaves
        int right = solve1(curr->right, curr);  // Current node will become parent node

        return left+right;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        // Approach 1 : Using Parent Pointer
        return solve1(root, NULL);
    }
};