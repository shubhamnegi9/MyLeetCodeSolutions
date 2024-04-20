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
    // Using DFS
    void DFS(TreeNode* root, string curr, string &result) {
        
        if(!root) {     // if(root == NULL)
            return;
        }

        // Converting node to string and appending it before curr string (since we need the string from leaf to root)
        curr = string(1, char((root->val)+'a')) + curr;
        
        // Leaf node 
        if(!root->left && !root->right) {   // if(root->left == NULL && root->right==NULL)
            // If result string is empty or curr string is lexicographically smaller string than result string
            if(result == "" || curr < result) {
                result = curr;
            }
        }

        // Calling DFS to left and right subtrees
        DFS(root->left, curr, result);
        DFS(root->right, curr, result);
    }

    // Using BFS
    void BFS(TreeNode* root, string curr, string &result) {
        
        // Since at every node, we need node and the string formed till that node, so taking queue of type pair<TreeNode*, string>
        queue<pair<TreeNode*, string>> q;
        // Converting node to string and appending it before curr string
        curr = string(1, char((root->val)+'a')) + curr;
        q.push({root, curr});

        while(!q.empty()) {
            auto [node, str] = q.front();
            q.pop();

            // Leaf node 
            if(!node->left && !node->right) {   // if(node->left == NULL && node->right==NULL)
                // If result string is empty or curr string is lexicographically smaller string than result string
                if(result == "" || str < result) {
                    result = str;
                }
            }

            // Pushing left child to queue
            if(node->left) {    // if(node->left != NULL)
                q.push({node->left, string(1, char((node->left->val)+'a')) + str});
            }

            // Pushing right child to queue
            if(node->right) {   // if(node->right != NULL)
                q.push({node->right, string(1, char((node->right->val)+'a')) + str});
            }
        }
    }

    string smallestFromLeaf(TreeNode* root) {
        string result = "";
        // Using DFS
        // DFS(root, "", result);

        // Using BFS
        BFS(root, "", result);

        return result;
    }
};