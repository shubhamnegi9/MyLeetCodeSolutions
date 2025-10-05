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

class BSTIterator{
    stack<TreeNode*> st;
    bool reverse = false;

    public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();
        if(!reverse) {
            pushAll(temp->right);
        } else {
            pushAll(temp->left);
        }
        return temp->val;
    }

    private:
    void pushAll(TreeNode* root) {
        while(root != NULL) {
            st.push(root);
            if(!reverse) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
    }
};
    
class Solution {
public:
    
    void inorder(TreeNode* root, vector<int>& v) {
        if(root == NULL)
            return;
        
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    // Brute Force Approach
    // T.C. = O(n) for storing inorder traversal + O(n) for 2 sum
    // S.C. = O(n) for vector
    bool findTarget1(TreeNode* root, int k) {
        vector<int> v;
        inorder(root, v);

        // Vector v contains sorted inorder. Now apply 2 sum
        int i = 0, j = v.size()-1;

        while(i < j) {
            if(v[i] + v[j] == k) {
                return true;
            }
            else if(v[i] + v[j] < k) {
                i++;
            }
            else {
                j--;
            }
        }

        return false;
    }

    // Optimal Approach
    // T.C. = O(n)
    // S.C. = 2*O(h)
    bool findTarget2(TreeNode* root, int k) {
        if(root == NULL)
            return false;

        // Creating 2 objects for BSTIterator class 
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int n1 = l.next(), n2 = r.next();

        while(n1 < n2) {
            if(n1+n2 == k) {
                return true;
            }
            else if(n1+n2 < k) {
                n1 = l.next();
            } else {
                n2 = r.next();
            }
        }
        return false;
    }
    
    bool findTarget(TreeNode* root, int k) {
        // Brute Force Approach
        // return findTarget1(root, k);

        // Optimal Approach
        return findTarget2(root, k);
    }
};