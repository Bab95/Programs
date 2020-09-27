/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if(node->right){
            node = node->right;

            while(node->left!=NULL){
                node = node->left;
            }
            return node;
        }else if(node->parent){
            if(node==node->parent->left){
                //left most so need to return to parent......
                return node->parent;
            }else if(node==node->parent->right){
                //if right child return grand parent......
                while(node->parent){
                    if(node==node->parent->left){
                        return node->parent;
                    }
                    node = node->parent;
                }
                return NULL;
            }else{
                return NULL;
            }
        }
        return NULL;
    }
};
