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
#include <queue>
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return root;
        }
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            Node *tmp = q.front();
            q.pop();
            int size = q.size();
            if(tmp->left){
                q.push(tmp->left);
                q.push(tmp->right);
            }
            for(int i=0;i<size;i++){
                Node *tmp2 = q.front();
                q.pop();
                if(tmp2->left){
                    q.push(tmp2->left);
                    q.push(tmp2->right);
                }
                tmp->next = tmp2;
                tmp = tmp2;
            }
            tmp->next = NULL;
        }
        return root;
    }
};
