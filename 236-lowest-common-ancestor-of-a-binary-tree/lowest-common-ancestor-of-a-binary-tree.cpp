/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getRootToNodePath(TreeNode* root, vector<TreeNode*>& path, TreeNode* x) {
        if(root == NULL)
            return false;
        
        path.push_back(root);

        // Check only after pushing root->val in path
        if(root == x) {
            return true;
        }

        if(getRootToNodePath(root->left, path, x) || getRootToNodePath(root->right, path, x)) {
            return true;
        }

        // Remove last node added in path while backtracking
        path.pop_back();
        return false;
    }

    // Brute Force Approach
    // T.C. = O(2n)
    // S.C. = O(2n)
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;

        getRootToNodePath(root, path1, p);
        getRootToNodePath(root, path2, q);

        int n1 = path1.size(), n2 = path2.size(), i = 0, j = 0;
        TreeNode* LCA;
        while(i < n1 && j < n2) {
            if(path1[i] == path2[j]) {
                LCA = path1[i];     // Update LCA
            } else {
                break;
            }
            i++;
            j++;
        }

        return LCA;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Brute Force Approach
        return lowestCommonAncestor1(root, p, q);
    }
};