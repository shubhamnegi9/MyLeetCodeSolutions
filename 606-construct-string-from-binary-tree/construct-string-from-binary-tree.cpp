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
    void check(TreeNode* root, string &preOrder) {
        if(root == NULL)
            return;
        
        // Add current value to string 
        preOrder += to_string(root->val);

        // If node has left or right chid, add open parenthesis and move to left child
        // Once all left nodes are traversed, add closing parenthesis
        if(root -> left || root -> right) {
            preOrder += "(";
            check(root->left, preOrder);
            preOrder += ")";
        }

        // If root has right child, add open parenthesis and move to right child
        // Once completed add closing parenthesis
        if(root -> right) {
            preOrder += "(";
            check(root-> right, preOrder);
            preOrder += ")";
        }
    }

    string tree2str(TreeNode* root) {
        string preOrder = "";
        check(root, preOrder);
        return preOrder;
    }
};