/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    NodeCopy* clone(unordered_map<Node*,NodeCopy*>& mmap,Node* root,unordered_map<NodeCopy*,Node*>& _mmap){
        if(root==NULL){
            return NULL;
        }
        if(mmap.find(root)!=mmap.end()){
            return mmap[root];
        }
        NodeCopy* new_node = new NodeCopy(root->val);
        mmap[root] = new_node;
        _mmap[new_node] = root;
        new_node->left = clone(mmap,root->left,_mmap);
        new_node->right = clone(mmap,root->right,_mmap);
        return new_node;
    }
    void restore_random(NodeCopy* root,unordered_map<Node*,NodeCopy*>& mmap,unordered_map<NodeCopy*,Node*>& _mmap){
        if(root==NULL){
            return;
        }
        Node* original = _mmap[root];
        if(original->random!=NULL){
            root->random = mmap[original->random];
        }
        restore_random(root->left,mmap,_mmap);
        restore_random(root->right,mmap,_mmap);
    }
    NodeCopy* copyRandomBinaryTree(Node* root) {
        if(root==NULL){
            return NULL;
        }
        NodeCopy* new_root = NULL;
        unordered_map<Node*,NodeCopy*> mmap;
        unordered_map<NodeCopy*,Node*> _mmap;
        new_root = clone(mmap,root,_mmap);
        restore_random(new_root,mmap,_mmap);
        return new_root;
    }
};
