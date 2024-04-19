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

        if(curr == NULL)
            return 0;       // Return 0 as sum
        
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

    // Approach 2: Using flag
    int solve2(TreeNode* curr, bool isLeftLeaf) {

        if(curr == NULL)
            return 0;       // Return 0 as sum

        // Leaf node and left leaf
        if(curr->left == NULL && curr->right == NULL && isLeftLeaf) {
            return curr->val;
        }

        int left = solve2(curr->left, true);        // Passing true for leftLeaf
        int right = solve2(curr-> right, false);    // Passing false for leftLeaf

        return left+right;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        // Approach 1 : Using Parent Pointer
        // return solve1(root, NULL);

        // Approach 2: Using flag
        return solve2(root, false);
    }
};