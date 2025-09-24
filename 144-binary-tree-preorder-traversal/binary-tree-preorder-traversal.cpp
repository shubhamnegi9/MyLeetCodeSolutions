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
    vector<int> preorderTraversal(TreeNode* root) {
        // Morris Preorder Travrsal
        vector<int> preorder;
        TreeNode* curr = root;

        while(curr != NULL) {
            // Case 1
            if(curr->left == NULL) {
                preorder.push_back(curr->val);
                // Before moving to right, push curr value to preorder
                curr = curr->right;
            }
            // Case 2
            else {
                TreeNode* prev = curr->left;

                while(prev->right != NULL && prev->right != curr) {
                    prev = prev->right;
                }

                if(prev->right == NULL) {
                    prev->right = curr;
                    // Before moving to left, push curr value to preorder
                    preorder.push_back(curr->val);
                    curr = curr->left;
                } 
                else {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
};