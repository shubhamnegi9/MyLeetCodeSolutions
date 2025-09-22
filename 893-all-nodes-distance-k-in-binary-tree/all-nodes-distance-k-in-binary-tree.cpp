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
    void createParentMapping(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parentMap) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node->left) {
                parentMap[node->left] = node;   // key will be left child and value will be parent
                q.push(node->left);
            }

            if(node->right) {
                parentMap[node->right] = node;  // key will be right child and value will be parent
                q.push(node->right);
            }
        }
    }

    // T.C. = O(n) + O(n)
    // S.C. = O(n) + O(n) + O(n)
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        if(root == NULL)
            return result;

        unordered_map<TreeNode*, TreeNode*> parentMap;
        createParentMapping(root, parentMap);

        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;
        q.push(target);
        visited[target] = true;
        int currLevel = 0;

        while(!q.empty()) {
            int n = q.size();
            // First check if currLevel == k, and then increment currLevel  
            if(currLevel == k) {
                break;
            } 
            currLevel++;

            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }

                if(node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                }

                if(parentMap[node] && !visited[parentMap[node]]) {
                    q.push(parentMap[node]);
                    visited[parentMap[node]] = true;
                }

            }
        }

        while(!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};