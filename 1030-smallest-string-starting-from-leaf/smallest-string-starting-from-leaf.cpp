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
    // Using DFS
    void DFS(TreeNode* root, string curr, string &result) {
        
        if(!root) {     // if(root == NULL)
            return;
        }

        // Converting node to string and appending it before curr string (since we need the string from leaf to root)
        curr = string(1, char((root->val)+'a')) + curr;
        
        // Leaf node 
        if(!root->left && !root->right) {   // if(root->left == NULL && root->right==NULL)
            // If result string is empty or curr string is lexicographically smaller string than result string
            if(result == "" || curr < result) {
                result = curr;
            }
        }

        // Calling DFS to left and right subtrees
        DFS(root->left, curr, result);
        DFS(root->right, curr, result);
    }

    string smallestFromLeaf(TreeNode* root) {
        string result = "";
        // Using DFS
        DFS(root, "", result);

        return result;
    }
};