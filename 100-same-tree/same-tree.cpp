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
    // Using preorder traversal
    bool isSameTree1(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL)
            return (p == q); // If p and q are null then return true, else if any of them is not null then return false
        
        return (p->val == q->val) &&
            isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right);
    }

    // Using inorder traversal
    bool isSameTree2(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL)
            return (p == q); // If p and q are null then return true, else if any of them is not null then return false
        
        return isSameTree(p->left, q->left) &&
            (p->val == q->val) &&
            isSameTree(p->right, q->right);
    }
    
    // Using postorder traversal
    bool isSameTree3(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL)
            return (p == q); // If p and q are null then return true, else if any of them is not null then return false
        
        return isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right) &&
            (p->val == q->val);
    }

    // Using level order traversal
    bool isSameTree4(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL)
            return (p == q); // If p and q are null then return true, else if any of them is not null then return false
        
        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);

        while(!q1.empty() && !q2.empty()) {
            TreeNode* node1 = q1.front();
            q1.pop();
            TreeNode* node2 = q2.front();
            q2.pop();

            // If node values are not same return false.
            // Note that we have not returned true for same nodes here as we need to check for further nodes also in case of same nodes.
            if(node1->val != node2->val) {
                return false;       
            }

            if(node1->left && node2->left) {
                q1.push(node1->left);
                q2.push(node2->left);
            }
            else if(node1->left || node2->left) {
                return false;   // Not same left nodes
            }

            if(node1->right && node2->right) {
                q1.push(node1->right);
                q2.push(node2->right);
            }
            else if(node1->right || node2->right) {
                return false;   // Not same right nodes
            }
        }

        return true;    // Finally return true
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Using preorder traversal
        // return isSameTree1(p, q);

        // Using inmorder traversal
        // return isSameTree2(p, q);

        // Using postorder traversal
        // return isSameTree3(p, q);

        // Using level order traversal
        return isSameTree4(p, q);
    }
};