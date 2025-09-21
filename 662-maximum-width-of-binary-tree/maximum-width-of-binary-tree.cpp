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
    // T.C. = O(n)
    // S.C. = O(n)
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        int maxWidth = 0;

        while(!q.empty()) {
            int size = q.size();
            int minIdx = q.front().second;  // Index of first node at that level will give minIdx
            int firstIdx, lastIdx;
            for(int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                TreeNode* node = p.first;
                long long int index = p.second - minIdx;      // Modified index
                if(i == 0)  
                    firstIdx = index;
                if(i == size-1)
                    lastIdx = index;
                if(node->left)
                    q.push({node->left, 2*index+1});
                if(node->right)
                    q.push({node->right, 2*index+2});
            }
            maxWidth = max(maxWidth, lastIdx - firstIdx + 1);
        }

        return maxWidth;
    }
};