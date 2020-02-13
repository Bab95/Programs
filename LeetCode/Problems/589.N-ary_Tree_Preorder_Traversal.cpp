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
#include <stack>
class Solution {
public:

    vector<int> preorder(Node* root) {
        vector<int> result;
        if(root==NULL){
            return result;
        }
        stack<Node*> stac;
        stac.push(root);
        Node *p;
        while(!stac.empty()){
            p = stac.top();
            stac.pop();
            int n = p->children.size();
            for(int i=n-1;i>=0;i--){
                stac.push(p->children[i]);
            }
            result.push_back(p->val);
        }
        return result;
    }
};
