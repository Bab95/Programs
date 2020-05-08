/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* getnext(Node* p){
        while(p){
            if(p->left){
                return p->left;
            }else if(p->right){
                return p->right;
            }
            p = p->next;
        }
        return p;
    }
    void connectNext(Node* root){
        Node* current = root;
        while(current){
            Node* p = current;
            while(p){
                if(p->left){
                    p->left->next = (p->right)?p->right:getnext(p->next);
                }
                if(p->right){
                    p->right->next = getnext(p->next);
                }
                p = p->next;
            }
            if(current->left){
                current = current->left;
            }else if(current->right){
                current = current->right;
            }else{
                current = current->next;
            }
        }
    }

    Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }
        root->next = NULL;
        connectNext(root);
        return root;
    }
};
