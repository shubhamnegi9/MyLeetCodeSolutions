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

    bool checkStrictlyIncreasing(vector<int> v) {
        for(int i = 0; i < v.size()-1; i++) {
            if(v[i] >= v[i+1])
                return false;
        }   
        return true;
    }

    bool checkStrictlyDecreasing(vector<int> v) {
        for(int i = 0; i < v.size()-1; i++) {
            if(v[i] <= v[i+1])
                return false;
        }   
        return true;
    }

    bool isEvenOddTree(TreeNode* root) {

        // Using BFS
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            cout << level << endl;
            int n = q.size();
            vector<int> v;
            while(n--) {
                TreeNode* node = q.front();
                q.pop();
                // Even Level
                if(level%2 == 0) {
                    if(node->val % 2 == 0)
                        return false;
                    v.push_back(node->val);
                }
                // Odd Level
                else {
                    if(node->val % 2 == 1)
                        return false;
                    v.push_back(node->val);
                }
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                
            }
            // Even Level
            if(level%2 == 0) {
                if(v.size()>1 && !checkStrictlyIncreasing(v)) {
                    return false;
                }
            }
            // Odd Level
            else {
                if(v.size()>1 && !checkStrictlyDecreasing(v))
                    return false;
            }
            level++;
        }
        return true;
    }
};