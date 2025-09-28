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

    TreeNode* findlastRight(TreeNode* node) {
        if(node->right == NULL)
            return node;
     
        return findlastRight(node->right);
    }

    // First way of deleting node 
    TreeNode* helper1(TreeNode* deletedNode) {
        // Edge case
        // If only one subtree of deletedNode
        if(deletedNode->left == NULL)
            return deletedNode->right;
        else if(deletedNode->right == NULL)
            return deletedNode->left;
        
        // Linking last right child in left subtree of deletedNode to right subtree of deletedNode
        TreeNode* rightChild = deletedNode->right;
        TreeNode* lastRightInLeftSubtree = findlastRight(deletedNode->left);
        lastRightInLeftSubtree ->right = rightChild;

        return deletedNode->left;   // return left subtree of deletedNode to link to its parent
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return NULL;
        
        if(root->val == key) {
            return helper1(root);      // Pass node to be deleted to helper function
        }

        TreeNode* temp = root;  // Creating temp pointer as we need to return root later

        while(temp) {
            // Checking whether to search left subtree or right subtree using key
            if(key <= temp->val) {
                // Search left subtree
                if(temp->left != NULL && key == temp->left->val) {
                    // Deleted node found in temp->left
                    // Link the subtree returned from helper to parent of temp (temp->left)
                    temp->left = helper1(temp->left); 
                    break;      // Break after deleting the required node
                }
                else {
                    temp = temp->left;
                }
            }
            else {
                // Search right subtree
                if(temp->right != NULL && key == temp->right->val) {
                    // Deleted node found in temp->right
                    // Link the subtree returned from helper to parent of temp (temp->right)
                    temp->right = helper1(temp->right); 
                    break;      // Break after deleting the required node
                }
                else {
                    temp = temp->right;
                }
            }
        }

        return root;
    }
};