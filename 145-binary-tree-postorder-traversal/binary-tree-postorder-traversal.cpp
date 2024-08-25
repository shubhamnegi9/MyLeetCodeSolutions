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
    void postorderTraversalUtil(TreeNode* root, vector<int> &postorder) {
         // Base condition
        if(root==NULL) {
            return;
        }
        
        postorderTraversalUtil(root->left, postorder);
        postorderTraversalUtil(root->right, postorder);
        postorder.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        postorderTraversalUtil(root, postorder);
        return postorder;
    }
};