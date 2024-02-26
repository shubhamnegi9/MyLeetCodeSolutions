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
    bool isSameTreeDFS(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;    // Same Tree
        
        if(p == NULL || q == NULL) {    // Same as (p == NULL and q != NULL) || (p != NULL and q == NULL)
            return false;   // Not Same Tree
        }

        // Checking for values at nodes
        if(p->val != q->val) {
            return false;   // Not Same Tree
        }

        // Checking for equalness of left subtree as well as right subtreee using recurison
        return isSameTreeDFS(p->left, q->left) && isSameTreeDFS(p->right, q->right);

    }

    // Using BFS
    bool isSameTreeBFS(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;    // Same Tree
        
        if(p == NULL || q == NULL) {    // Same as (p == NULL and q != NULL) || (p != NULL and q == NULL)
            return false;   // Not Same Tree
        }

        // Queue for BFS traversal
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        q1.push(p);
        q2.push(q);

        while(!q1.empty() && !q2.empty()) {
            TreeNode* node1 = q1.front();
            q1.pop();
            TreeNode* node2 = q2.front();
            q2.pop();

            // Checking for values at nodes
            if(node1->val != node2->val) {
                return false;   // Not Same Tree
            }
            
            // If left subtree of both nodes are not null, then push them into queue
            if(node1->left != NULL && node2->left != NULL) {
                q1.push(node1->left);
                q2.push(node2->left);
            }
            // Left subtree of any node is null
            else if(node1->left != NULL || node2->left != NULL) {
                return false;   // Not Same Tree
            }

            // If right subtree of both nodes are not null, then push them into queue
            if(node1->right != NULL && node2->right != NULL) {
                q1.push(node1->right);
                q2.push(node2->right);
            }
            // Right subtree of any node is null
            else if(node1->right != NULL || node2->right != NULL) {
                return false;   // Not Same Tree
            }

        }

        return true;    // Same Tree
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Using DFS
        // return isSameTreeDFS(p, q);

        // Using BFS
        return isSameTreeBFS(p, q);
    }
};