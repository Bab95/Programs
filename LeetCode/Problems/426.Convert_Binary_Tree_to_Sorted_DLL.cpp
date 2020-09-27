/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root==NULL){
            return root;
        }
        stack<Node*> stk;
        Node* head = NULL;
        Node* prev = NULL;
        Node* current = root;
        while(current!=NULL||!stk.empty()){
            while(current!=NULL){
                stk.push(current);
                current = current->left;
            }
            current = stk.top();
            stk.pop();
            if(prev==NULL){
                head = current;
                prev = current;
            }else{
                prev->right = current;
                current->left = prev;
                prev = current;
            }
            current = current->right;
        }
        head->left = prev;
        prev->right = head;
        return head;
    }
};
