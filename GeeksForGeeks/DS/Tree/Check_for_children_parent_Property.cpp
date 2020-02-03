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
bool sumProperty(struct node *root){
  if(root==NULL){
    return true;
  }
  if(root->left==NULL&&root->right==NULL){
    return true;
  }
  int left = (root->left==NULL)?0:root->left->data;
  int right = (root->right==NULL)?0:root->right->data;
  if(left+right==root->data){
    return sumProperty(root->left)&&sumProperty(root->right);
  }
  return false;
}
int main(){
  struct node *root = getnode(10);
  root->left = getnode(8);
  root->right = getnode(2);
  root->left->left = getnode(3);
  root->left->right = getnode(5);
  root->right->right = getnode(2);
  if(sumProperty(root)){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}
