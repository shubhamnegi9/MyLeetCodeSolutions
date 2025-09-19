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
    // Using Iterative Level Order Traversal
    vector<vector<int>> verticalTraversalUsingLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        
        queue<pair<TreeNode*, pair<int, int>>> q;    // We need to store 3 things thats why
        map<int, map<int, multiset<int>>> mpp;

        q.push({root, {0, 0}});      // Root node is at horizontal distance 0 and vertical distance 0

        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int x = p.second.first;     // Horizontal distance of node
            int y = p.second.second;    // Vertical distance of node

            mpp[x][y].insert(node->val);    // node->val is added in multiset 

            if(node->left) {
                q.push({node->left, {x-1, y+1}});
            }

            if(node->right) {
                q.push({node->right, {x+1, y+1}});
            }
        }

        for(auto p: mpp) {
            vector<int> col;
            for(auto q: p.second) {
                // One way to push in col vector is to iterate in q.second (multiset) and push in col vector using push_back()
                // Another way to push in col vector is by below using iterators
                // Using insert method, we need to specify at which position we need to insert in col vector
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }

    void preorder(TreeNode* node, map<int, map<int, multiset<int>>>& mpp, int x, int y) {
        if(node == NULL)
            return;
        
        mpp[x][y].insert(node->val);

        preorder(node->left, mpp, x-1, y+1);
        preorder(node->right, mpp, x+1, y+1);
    }

    vector<vector<int>> verticalTraversalUsingPreOrder(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> mpp;

        preorder(root, mpp, 0, 0);

        for(auto p: mpp) {
            vector<int> col;
            for(auto q: p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Using Iterative Level Order Traversal
        // return verticalTraversalUsingLevelOrder(root);

        // Using Recursive Preorder Traversal
        return verticalTraversalUsingPreOrder(root);
    }
};