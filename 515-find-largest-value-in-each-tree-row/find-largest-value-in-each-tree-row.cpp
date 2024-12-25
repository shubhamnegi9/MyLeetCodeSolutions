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
    // Using BFS
    // T.C. = O(n) for visiting each node
    // S.C. = O(n) for queue
    void largestValuesBFS(TreeNode* root, vector<int>& result) {
        if(root == NULL)
            return;
        
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty()) {
            int maxEle = INT_MIN;
            int n = que.size();
            while(n--) {
                TreeNode* node = que.front();
                que.pop();
                maxEle = max(maxEle, node->val);
                if(node->left != NULL)
                    que.push(node->left);
                if(node->right != NULL)
                    que.push(node->right);
            }
            result.push_back(maxEle);
        }
    }
    
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        
        // Using BFS
        largestValuesBFS(root, result);
        
        return result;
    }
};