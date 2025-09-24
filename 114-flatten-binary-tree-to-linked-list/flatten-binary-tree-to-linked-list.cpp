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
    // Approach 1 (Recursive Way)
    // T.C. = O(n)
    // S.C. = O(n)
    TreeNode* prev = NULL;
    void flatten1(TreeNode* root) {
        if(root == NULL)
            return;
        
        flatten1(root->right);
        flatten1(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }

    // Approach 2 (Iterative Stack Way)
    // T.C. = O(n)
    // S.C. = O(n)
    void flatten2(TreeNode* root) {
        if(root == NULL)
            return;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            if(node->right)
                st.push(node->right);
            if(node->left)
                st.push(node->left);
            
            if(!st.empty())
                node->right = st.top();
            node->left = NULL;
        }
    }

    // Approach 3 (Morris Traversal)
    // T.C. = O(n)
    // S.C. = O(1)
    void flatten3(TreeNode* root) {
        if(root == NULL)
            return;
        
        TreeNode* curr = root;

        while(curr != NULL) {
            if(curr->left != NULL) {
                TreeNode* prev = curr->left;
                while(prev->right) {
                    prev = prev->right;
                }

                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }

    void flatten(TreeNode* root) {
        // Approach 1 
        // return flatten1(root);

        // Approach 2
        // return flatten2(root);

        // Approach 3
        return flatten3(root);
    }
};