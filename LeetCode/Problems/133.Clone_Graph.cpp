/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* _clone(unordered_map<Node*,Node*>& mmap,Node* node){
        if(node==NULL){
            return NULL;
        }
        if(mmap.find(node)!=mmap.end()){
            return mmap[node];
        }
        Node* _node = new Node(node->val);
        mmap[node] = _node;
        for(auto it=node->neighbors.begin();it!=node->neighbors.end();++it){
            _node->neighbors.push_back(_clone(mmap,*it));
        }
        return _node;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mmap;
        Node* newNode = NULL;
        newNode = _clone(mmap,node);
        return newNode;
    }
};
