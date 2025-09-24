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
    // T.C. = O(n) + O(n) amortized = O(n)
    // S.C. = O(1)
    vector<int> inorderTraversal(TreeNode* root) {
        // Using Morris Inorder Traversal
        vector<int> inorder;
        TreeNode* curr = root;

        while(curr != NULL) {
            // Case 1
            if(curr->left == NULL) {
                // Push curr value in inorder and move curr to right
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            // Case 2
            else {
                TreeNode* prev = curr->left;

                while(prev->right != NULL && prev->right != curr) {
                    prev = prev->right;
                }

                if(prev->right == NULL) {
                    // Create threaded link to curr and move curr to left
                    prev->right = curr;
                    curr = curr->left;
                }
                else {
                    // Remove threaded link to curr and move curr to right
                    prev->right = NULL;
                    // Push curr value in inorder
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return inorder;
    }
};