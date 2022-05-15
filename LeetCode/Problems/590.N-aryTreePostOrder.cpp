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
    void postorder(Node* root, vector<int>& result){
        if (root == NULL){
            return;
        }
        for (int i=0;i<root->children.size();i++){
            postorder(root->children[i], result);
        }
        result.push_back(root->val);
        return;
    }
    vector<int> postorder(Node* root) {
        if (root == NULL){
            return {};
        }
        vector<int> result;
        postorder(root, result);
        return result;
    }
};