/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    void traverse(Node* root, vector<int> &result) {
        // Base Case
        if(!root)
            return;
        
        // First, visit all children
        for(Node* &node: root->children) {
            traverse(node, result);
        }
        
        // Then, add the current node's value
        result.push_back(root->val);
    }
    
    // Recursive Approach
    vector<int> postOrderRecursive(Node* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }
    
    // Iterative Approach
    vector<int> postOrderIterative(Node* root) {
        vector<int> result;
        // If the root is null, return the empty list
        if (root == nullptr) 
            return result;
        
        stack<Node*> nodeStack;
        nodeStack.push(root);
        
        // Traverse the tree using the stack
        while(!nodeStack.empty()) {
            Node* currNode = nodeStack.top();
            nodeStack.pop();
            result.push_back(currNode->val);
            
            // Push all the children of the current node to the stack
            for(Node* &node: currNode->children) {
                nodeStack.push(node);
            }
        }
        
         // Reverse the result list to get the correct postorder traversal
        reverse(result.begin(), result.end());
        return result;
    }
    
    vector<int> postorder(Node* root) {
        // return postOrderRecursive(root);
        
        return postOrderIterative(root);
    }
};