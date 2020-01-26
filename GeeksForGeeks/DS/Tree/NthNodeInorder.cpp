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
void inorder(struct node *root,int *i,int n){
  if(root==NULL){
    return;
  }
  inorder(root->left,i,n);
  if(*i==n){
    cout<<root->data<<endl;
    *i = *i+1;
    return;
  }
  *i = *i+1;
  Inorder(root->right,i,n);
}
int main(){
  struct node *root = getnode(10);
  root->left = getnode(20);
  root->right = getnode(30);
  root->left->left = getnode(40);
  root->left->right = getnode(50);
  int i = 1;
  int n = 4;
  inorder(root,&i,n);
  return 0;
}
