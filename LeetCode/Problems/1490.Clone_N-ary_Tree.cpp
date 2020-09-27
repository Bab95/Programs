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
    Node* clone(Node* root){
        if(root==NULL){
            return NULL;
        }
        Node* new_node = new Node(root->val);
        for(int i=0;i<root->children.size();++i){
            new_node->children.push_back(clone(root->children[i]));
        }
        return new_node;
    }
    Node* cloneTree(Node* root) {
        return clone(root);
    }
};
