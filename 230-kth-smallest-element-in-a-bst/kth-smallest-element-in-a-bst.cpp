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
    // Brute Force Approach
    // T.C. = O(n) for level order + O(nlogn) for sorting
    // S.C. = O(n) for vector + O(n) for queue
    int kthSmallest1(TreeNode* root, int k) {
        vector<int> ans;
        
        if(root == NULL)
            return -1;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            for(int i = 0; i < q.size(); i++) {
                TreeNode* node = q.front();
                q.pop();
                ans.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }

        sort(ans.begin(), ans.end());
        return ans[k-1];
    }   
    
    int kthSmallest(TreeNode* root, int k) {
        // Brute Force Approach
        return kthSmallest1(root, k);
    }
};