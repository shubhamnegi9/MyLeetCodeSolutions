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
    // T.C. = O(m*n)
    // S.C. = O(1) extra space / O(h) recursion stack (auxiliary) space 
    int heightOfTree(TreeNode* root, int nodeToRemove) {    // O(n)
        if(root == NULL || root->val == nodeToRemove) {
            return 0;
        }
        
        return 1 + max(heightOfTree(root->left, nodeToRemove), heightOfTree(root->right,  nodeToRemove));
    }
    
    vector<int> treeQueries1(TreeNode* root, vector<int>& queries) {
        vector<int> result;
        for(int &q: queries) {      // O(m)
            TreeNode* temp = root;
            int height = heightOfTree(temp, q);
            // height -> Number of nodes in longest path
            // (height-1) -> Number of edges in longest path
            result.push_back(height-1);
        }
        return result;
    }
    
    // Optimal Approach
    // T.C. = O(n + m) 
    // S.C. = O(n) + O(n) + O(n) + O(n) extra space
    //       = O(4n) = O(n)
    int level[100001];                  // Level of each node
    int height[100001];                 // Height of each node (In terms of number of nodes in that path)
    int levelMaxHeight[100001];         // Max height in each level
    int levelSecondMaxHeight[100001];   // Second max height in each level
    
    int findHeight(TreeNode* root, int l) {    // O(n)
        if(root == NULL) {
            return 0;
        }
        
        level[root->val] = l;
        
        int h = 1 + max(findHeight(root->left, l+1), findHeight(root->right,  l+1));    // Increasing level on calling recursive function
        height[root->val] = h;
        
        if(h > levelMaxHeight[l]) {
            levelSecondMaxHeight[l] = levelMaxHeight[l];    // First fill levelSecondMaxHeight[l] with levelMaxHeight[l]
            levelMaxHeight[l] = h;
        } else if(h > levelSecondMaxHeight[l]) {
            levelSecondMaxHeight[l] = h;
        }
        
        return h;
    }
    
    vector<int> treeQueries2(TreeNode* root, vector<int>& queries) {
        // Calling findHeight method to preprocess binary tree and fill all required arrays
        findHeight(root, 0);    // Passing level 0 for root
        
        vector<int> result;
        for(int &node: queries) {   // O(m)
            int L = level[node];    // Level of this node
            int H = (height[node] == levelMaxHeight[L]) ? levelSecondMaxHeight[L] : levelMaxHeight[L];  // Max height in current level
            result.push_back(L+H-1);
        }
        
        return result;
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // Brute Force Approach
        // return treeQueries1(root, queries);
        
        // Optimal Approach
        return treeQueries2(root, queries);
    }
};