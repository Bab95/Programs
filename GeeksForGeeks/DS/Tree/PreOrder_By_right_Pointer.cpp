#include <iostream>
using namespace std;
struct node{
  int data;
  struct node *left,*right;
};
struct node *getnode(int data){
  struct node *tmp = (struct node *)malloc(sizeof(struct node));
  tmp->left = tmp->right = NULL;
  tmp->data = data;
  return tmp;
}
void modifyTree(struct node *root){
  if(root==NULL){
    return;
  }
  stack<struct node *> stk;
  stk.push(root);
  struct node *pre = NULL;
  while(!stk.empty()){
    struct node *current = stk.top();
    stk.pop();
    if(current->right){
      stk.push(current->right);
    }
    if(current->left){
      stk.push(current->left);
    }
    if(pre!=NULL){
      pre->right = current;
    }
    pre = current;
  }
}
void printTree(struct node *root){
  while(root!=NULL){
    cout<<root->data<<" ";
    root = root->right;
  }
  cout<<endl;
  return;
}
struct node *buildTree(){
  struct node *root = getnode(10);
  root->left = getnode(8);
  root->right = getnode(2);
  root->left->left = getnode(3);
  root->left->right = getnode(5);
  return root;
}
int main(){
  struct node *root = buildTree();
  modifyTree(root);
  printTree(root);
}
