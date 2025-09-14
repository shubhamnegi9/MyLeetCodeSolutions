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
    
    int maxDepth1(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        return 1 + max(maxDepth1(root->left), maxDepth1(root->right));
    }

    int maxDepth2(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            level++;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }

        return level;
    }
    
    int maxDepth(TreeNode* root) {
        // Recursive Apprroach
        // return maxDepth1(root);

        // Iterative Level Order Approach
        return maxDepth2(root);
    }
};