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
    
    vector<int> postOrderRecursive(Node* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }
    
    vector<int> postorder(Node* root) {
        return postOrderRecursive(root);
    }
};