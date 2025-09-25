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
    // T.C. = O(h) = O(logn)
    // S.C. = O(1)
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)
            return new TreeNode(val);
        
        TreeNode* curr = root;
        while(true) {
            if(val > curr->val) {
                // Go to right subtree   
                if(curr->right != NULL)
                    curr = curr->right;
                else {
                    // Attach new node to right of curr and break
                    curr->right = new TreeNode(val);
                    break;
                }
            }
            else {
                // Go to left subtree
                if(curr->left != NULL)
                    curr = curr->left;
                else {
                    // Attach new node to left of curr and break
                    curr->left = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};