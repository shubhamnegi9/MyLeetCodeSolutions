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
    vector<int> postorderTraversal(TreeNode* root) {
        // Morris Postorder Traversal
        vector<int> ans;
        TreeNode* curr = root;

        // Order of traversal: (Root Right Left)
        while(curr != NULL) {
            // Case 1
            if(curr->right == NULL) {
                ans.push_back(curr->val);
                curr = curr->left;
            }
            // Case 2
            else {
                TreeNode* prev = curr->right;

                // Finding leftmost node in right subtree
                while(prev->left != NULL && prev->left != curr) {
                    prev = prev->left;
                }

                if(prev->left == NULL) {
                    // Create thread from prev to curr
                    prev->left = curr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
                else {
                    // Remove thread from prev to curr
                    prev->left = NULL;
                    curr = curr->left;
                }
            }
        }

        // Reverse ans vector to get postorder traversal
        // (Root Right Left) ----> (Left Right Root)
        reverse(ans.begin(), ans.end());
        return ans;
    }
};