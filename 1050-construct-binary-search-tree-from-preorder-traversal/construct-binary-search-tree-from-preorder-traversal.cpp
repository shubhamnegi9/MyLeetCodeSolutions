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
    TreeNode* buildSubTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int,int>& inMap) {
        // Base Case
        if((preStart > preEnd) || (inStart > inEnd))
            return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRootPos = inMap[root->val];
        int numsLeft = inRootPos - inStart;

        root->left = buildSubTree(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRootPos-1, inMap);
        root->right = buildSubTree(preorder, preStart+numsLeft+1, preEnd, inorder, inRootPos+1, inEnd, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;

        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return buildSubTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
    }

    // Better Approach
    // T.C. = O(nlogn) for sorting + O(n) for building tree using preorder and inorder
    // S.C. = O(n) extra space for inorder vector + O(n) extra space for map 
    TreeNode* bstFromPreorder1(vector<int>& preorder) {
        // Creating copy of preorder vector
        vector<int> inorder(preorder.begin(), preorder.end());

        sort(inorder.begin(), inorder.end());

        return buildTree(preorder, inorder);
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // Better Approach
        return bstFromPreorder1(preorder);
    }
};