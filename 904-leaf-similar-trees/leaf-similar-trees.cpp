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
    void findLeafNodes(vector<int> & leafNodes, TreeNode* root) {
        if(root == NULL) 
            return;
        
        if(root->left == NULL && root-> right== NULL) {
            leafNodes.push_back(root->val);
        }
        findLeafNodes(leafNodes, root->left);
        findLeafNodes(leafNodes, root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafNodes1, leafNodes2;
        findLeafNodes(leafNodes1, root1);
        findLeafNodes(leafNodes2, root2);
        return leafNodes1 == leafNodes2;
    }
};