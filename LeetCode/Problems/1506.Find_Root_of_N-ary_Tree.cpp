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
    Node* findRoot(vector<Node*> tree) {
        unordered_map<Node*,Node*> parent;
        for(int i=0;i<tree.size();++i){
            Node* current = tree[i];
            for(int j=0;j<tree[i]->children.size();++j){
                parent[tree[i]->children[j]] = current;
            }
        }
        for(int i=0;i<tree.size();++i){
            if(parent.find(tree[i])==parent.end()){
                return tree[i];
            }
        }
        return NULL;
    }
};
/*
[1,null,3,2,4,null,5,6]
[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
[1,null,10,3,null,5,0,null,6]
*/
