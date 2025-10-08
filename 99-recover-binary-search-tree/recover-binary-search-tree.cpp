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
    void inorder(TreeNode* root, vector<int>& v) {
        if(root == NULL)
            return;
        
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    void inorderAgain(TreeNode* root, vector<int>& v, int& i) {
        if(root == NULL)
            return;
        
        inorderAgain(root->left, v, i);
        // Visiting the node
        if(root->val != v[i]) {
            root->val = v[i];
        }
        i++;    // Moving i ahead after visiting node
        inorderAgain(root->right, v, i);
    }

    // Brute Force Approach
    // T.C. = O(2n) + O(nlogn)
    // S.C. = O(n) extra space
    void recoverTree1(TreeNode* root) {
        if(root == NULL)
            return;
        
        vector<int> v;
        inorder(root, v);

        sort(v.begin(), v.end());
        int i = 0;
        inorderAgain(root, v, i);
    }
    
    void recoverTree(TreeNode* root) {
        // Brute Force Approach
        recoverTree1(root);
    }
};