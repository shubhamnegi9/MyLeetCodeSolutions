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
    // T.C. = O(n)
    // S.C. = O(h) = O(logn)
    void preorder(TreeNode* root, int& count) {
        if(root == NULL)
            return;
        
        count++;
        preorder(root->left, count);
        preorder(root->right, count);
    }

    int findLeftHeight(TreeNode* root) {
        int height = 0;
        while(root) {
            height++;
            root = root->left;
        }
        return height;
    }

    int findRightHeight(TreeNode* root) {
        int height = 0;
        while(root) {
            height++;
            root = root->right;
        }
        return height;
    }

    // Optimal Approach
    // T.C. = O(logn)^2
    // O(h) = O(logn)
    int countNodes2(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int lh = findLeftHeight(root);  // Pass root, not root->left in order to include root also
        int rh = findRightHeight(root); // Pass root, not root->right in order to include root also

        // Full Bianry Tree found
        if(lh == rh)
            return (1 << lh) - 1;       // Same as (2^lh - 1)
        
        return 1 + countNodes2(root->left) + countNodes2(root->right);
    }

    int countNodes(TreeNode* root) {
        // Brute Force Approach
        // int count = 0;
        // preorder(root, count);
        // return count;

        // Optimal Approach
        return countNodes2(root);
    }
};