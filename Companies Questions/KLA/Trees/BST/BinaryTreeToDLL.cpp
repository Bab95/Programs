#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

Node *bTreeToCList(Node *root)
{
    //add code here.
    stack<Node*> stk;
    Node* current = root;
    Node* prev = NULL;
    Node* head;
    while(current||!stk.empty()){
        while(current){
            stk.push(current);
            current = current->left;
        }
        current = stk.top();
        stk.pop();
        if(prev==NULL){
            prev = current;
            head = current;
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