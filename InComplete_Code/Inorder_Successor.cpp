#include <iostream>
using namespace std;
struct node{
  int data;
  struct node *left,*right;
};
struct node *getnode(int data){
  struct node *tmp = (struct node*)malloc(sizeof(struct node));
  tmp->data = data;
  tmp->left = NULL;
  tmp->right = NULL;
  return tmp;
}
struct node *tmp = NULL;
struct node* leftMost(struct node *root){
  while(root!=NULL&&root->left!=NULL){
    root = root->left;
  }
  return root;
}
struct node* rightMost(struct node *root){
  while(root!=NULL&&root->right!=NULL){
    root = root->right;
  }
  return root;
}
void findInorderSuccessor(struct node *root,struct node *x,struct node **successor){
  if(root==NULL){
    return;
  }
  if(x==root||tmp = findInorderSuccessor(root->left,x)||tmp = findInorderSuccessor(root->right,x)){
    if(tmp!=NULL){
      if(root->left==tmp){
        *successor = root;
        tmp = NULL;
      }
    }

  }


}
struct node *inorderSuccessor(struct node *root,struct node *x){
  if(x->right!=NULL){
    struct node *successor = leftMost(x->right);
    return successor;
  }
  if(x->right==NULL){
    struct node *rmost = rightMost(root);
    if(x==rmost){
      return NULL;
    }
    else{
      struct node *successor = NULL;
      findInorderSuccessor(root,x,&successor);
      return successor;
    }
  }
}
int main(){

}
