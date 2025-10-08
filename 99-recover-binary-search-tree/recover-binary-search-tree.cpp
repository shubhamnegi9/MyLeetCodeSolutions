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
private:
TreeNode* prev;
TreeNode* first;
TreeNode* middle;
TreeNode* last;

public:
    void inorder(TreeNode* root, vector<int>& v) {
        if(root == NULL)
            return;
        
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    void inorderAgain(TreeNode* root, vector<int>& v, int& i) {
        if(root == NULL)
            return;
        
        inorderAgain(root->left, v, i);
        // Visiting the node
        if(root->val != v[i]) {
            root->val = v[i];
        }
        i++;    // Moving i ahead after visiting node
        inorderAgain(root->right, v, i);
    }

    // Brute Force Approach
    // T.C. = O(2n) + O(nlogn)
    // S.C. = O(n) extra space
    void recoverTree1(TreeNode* root) {
        if(root == NULL)
            return;
        
        vector<int> v;
        inorder(root, v);

        sort(v.begin(), v.end());
        int i = 0;
        inorderAgain(root, v, i);
    }
    
    void inorderOptimal(TreeNode* node) {
        if(node == NULL)
            return;
        
        inorderOptimal(node->left);

        // Condition for violation
        if(prev != NULL && node->val < prev->val) {
            // First violation
            if(first == NULL) {
                first = prev;
                middle = node;
            }
            // Second Violation
            else {
                last = node;
            }
        }
        prev = node;
    
        inorderOptimal(node->right);
    }

    // Optimal Approach
    // T.C. = O(n)
    // S.C. = O(1)
    void recoverTree2(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);

        inorderOptimal(root);

        if(first && last)           // First violation
            swap(first->val, last->val);
        else if(first && middle)    // Second violation
            swap(first->val, middle->val);
    }
    
    void recoverTree(TreeNode* root) {
        // Brute Force Approach
        // recoverTree1(root);

        // Optimal Approach
        recoverTree2(root); 
    }
};