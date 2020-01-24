#include <iostream>
#include <vector>
using namespace std;
struct node{
  int data;
  struct node *left,*right;
};
struct node *getNode(int data){
  struct node *tmp = (struct node *)malloc(sizeof(struct node));
  tmp->data = data;
  tmp->left = NULL;
  tmp->right = NULL;
  return tmp;
}
void inorderStore(struct node *root,vector<int> &inorder){
  if(root==NULL){
    return;
  }
  inorderStore(root->left,inorder);
  inorder.push_back(root->data);
  inorderStore(root->right,inorder);
}
void inordeReplaceSum(struct node *root,int *i,vector<int> &v){
  if(root==NULL){
    return;
  }
  inordeReplaceSum(root->left,i,v);
  root->data = v[*i-1]+v[*i+1];
  *i = *i+1;
  inordeReplaceSum(root->right,i,v);
}
void ReplaceWithSum(struct node *root){
  if(root==NULL){
    return;
  }
  vector<int> v;
  v.push_back(0);
  inorderStore(root,v);
  v.push_back(0);
  int ip = 1;
  inordeReplaceSum(root,&ip,v);
}
void inorderCheck(struct node *root){
  if(root==NULL){
    return;
  }
  inorderCheck(root->left);
  cout<<root->data<<" ";
  inorderCheck(root->right);
}
int main(){
    struct node* root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->right->left = getNode(6);
    root->right->right = getNode(7);
    ReplaceWithSum(root);
    inorderCheck(root);
}
