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
    int pseudoPathCount = 0;

    void pseudoPalindromicPathsCount(TreeNode* root, vector<int> &count) {
        // Base Case
        if(root == NULL)
            return;
        
        // Storing the count of each node in vector
        count[root->val]++;

        // Checking for pseudo palindromic path on reaching leaf node
        if(root->left == NULL && root->right == NULL) { 
            // Finding frequency of nodes whose count was odd
            int oddFreq = 0;
            for(int i = 1; i <= 9; i++) {
                if(count[i] % 2)
                    oddFreq++;
            }

            // If frequency of nodes whose count was odd <= 1 
            // then pseudo palindromic path found
            if(oddFreq <= 1)
                pseudoPathCount++;
        }
        
        pseudoPalindromicPathsCount(root -> left, count);
        pseudoPalindromicPathsCount(root -> right, count);

        // On backtracking from the node, reducing its count from vector
        // NOTE: In case vector was passed as a copy and not by reference, then this step is not required
        count[root->val]--;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        // Vector for storing count of each node in path
        // Since node value can be only from 1 to 9, so taking vector of size 10
        vector<int> count(10, 0);

        pseudoPalindromicPathsCount(root, count);
        return pseudoPathCount;
    }
};