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

    TreeNode* buildSubTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int> &inorderMap) {
        // Base case
        if((inStart > inEnd) || (postStart > postEnd))
            return NULL;
        
        // Create root node from last value of postorder
        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRootPos = inorderMap[root->val];
        int numsLeft = inRootPos - inStart;

        // While backtracking, attach root node of left subtree to root->left
        root->left = buildSubTree(inorder, inStart, inRootPos-1, postorder, postStart, postStart+numsLeft-1, inorderMap);
        // While backtracking, attach root node of right subtree to root->right
        root->right = buildSubTree(inorder, inRootPos+1, inEnd, postorder, postStart+numsLeft, postEnd-1, inorderMap);

        return root;
    }

    // T.C. = O(n)
    // S.C. = O(n)
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        // Edge case
        // If sizes of inorder and postorder are not same, return NULL
        if(inorder.size() != postorder.size())
            return NULL;

        unordered_map<int, int> inorderMap;

        for(int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        return buildSubTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inorderMap);
    }
};