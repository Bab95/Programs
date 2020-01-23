#include <iostream>
using namespace std;
struct node{
  int data;
  struct node *left,*right;
};
struct node *getnode(int data){
  struct node *tmp = (struct node *)malloc(sizeof(struct node));
  tmp->data = data;
  tmp->left = NULL;
  tmp->right = NULL;
  return tmp;
}
void morrisTraversal(struct node *root){
  struct node *pre,*current;
  if(root==NULL){
    return;
  }
  current = root;
  while(current!=NULL){
    if(current->left==NULL){
      cout<<current->data<<" ";
      current = current->right;
    }else{
      pre = current->left;
      while(pre->right!=NULL&&pre->right!=current){
        pre = pre->right;
      }
      if(pre->right==NULL){
        pre->right = current;
        current = current->left;
      }else{
        pre->right = NULL;
        cout<<current->data<<" ";
        current = current->right;
      }
    }
  }
}
struct node *buildtree(){
  struct node *root = getnode(1);
  root->left = getnode(2);
  root->right = getnode(3);
  root->left->left = getnode(4);
  root->left->left->right = getnode(6);
  root->left->right = getnode(5);
  root->right->right = getnode(7);
  root->right->right->left = getnode(9);
  return root;
}
int main(){
  struct node *root = buildtree();
  morrisTraversal(root);
}
