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

    // Using level wise BFS
    bool isEvenOddTreeUsingBFS(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
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

    // Using level wise BFS with better space 
    bool isEvenOddTreeUsingBFS2(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool evenLevel = true;
        while(!q.empty()) {
            int n = q.size();
            int prev;   // For tracking previous node in this level
            if(evenLevel) {
                prev = INT_MIN;
            }
            else {
                prev = INT_MAX;
            }
            while(n--) {
                TreeNode* curr = q.front();
                q.pop();
                // Even Level
                if(evenLevel && (curr->val % 2 == 0 || curr->val <= prev)) {
                    return false;
                }
                // Odd Level
                if(!evenLevel && (curr->val % 2 == 1 || curr->val >= prev)) {
                    return false;
                }
                // Assigning current node value to prev
                prev = curr->val;   
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            // Changing level
            evenLevel = !evenLevel;
        }
        return true;
    }

    bool isEvenOddTree(TreeNode* root) {

        // Using level wise BFS
        // return isEvenOddTreeUsingBFS(root);

        // Using level wise BFS with better space
        return isEvenOddTreeUsingBFS2(root);
    }
};