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
    
    vector<int> postorderTraversalUsing2Stack(TreeNode* root) {
        vector<int> result;

        if(root == NULL)
            return result;

        stack<TreeNode*> st1;
        stack<TreeNode*> st2;

        st1.push(root);

        while(!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop();
            st2.push(node);
            if(node->left)
                st1.push(node->left);
            if(node->right)
                st1.push(node->right);
        }

        while(!st2.empty()) {
            result.push_back(st2.top()->val);
            st2.pop();
        }

        return result;

    }

    vector<int> postorderTraversalUsing1Stack(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;
        
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if(node->left)
                st.push(node->left);
            if(node->right)
                st.push(node->right);
        }

        reverse(result.begin(), result.end());
        return result;
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        // return postorderTraversalUsing2Stack(root);

        return postorderTraversalUsing1Stack(root);
    }
};