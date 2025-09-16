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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if(root == NULL)
            return result;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty()) {
            int n = q.size();
            vector<int> ans(n);
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                
                // If level is even, fill from left to right, otherwise fill from right to left 
                int index = (level%2 == 0) ? i : n - i - 1;
                ans[index] = node->val;
            }
            level++;
            result.push_back(ans);
        }

        return result;
    }
};