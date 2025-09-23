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

    TreeNode* buildSubTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int> &inorderMap) {
        // Base condition
        // preorder or inorder have no nodes remaining
        if((preStart > preEnd) || (inStart > inEnd))
            return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRootPos = inorderMap[root->val];
        int numsLeft = inRootPos - inStart;     // Number of nodes on left of this root in inorder

        // buildSubTree will return root of the left subtree. So we need to assign/attach it to root->left
        root->left = buildSubTree(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRootPos-1, inorderMap);
        // buildSubTree will return root of the right subtree. So we need to assign/attach it to root->right
        root->right = buildSubTree(preorder, preStart+numsLeft+1, preEnd, inorder, inRootPos+1, inEnd, inorderMap);

        return root;
    }

    // T.C. = O(n)
    // S.C. = O(n)
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;

        for(int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;      // Key of map will be inorder value and value of map will be index
        }

        TreeNode* root = buildSubTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inorderMap);
        return root;
    }
};