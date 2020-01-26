#include <iostream>
#include <queue>
#include <stack>
#include <vector>
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
bool storePath(struct node *root,vector<struct node *> &path,int x){
  if(root==NULL){
    return false;
  }
  path.push_back(root);
  if(root->data==x){
    return true;
  }
  if(storePath(root->left,path,x)||storePath(root->right,path,x)){
    return true;
  }
  path.pop_back();
  return false;
}
void inorder(struct node *root){
  if(root==NULL){
    return;
  }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}
void reversePath(struct node *root,int x){
  std::vector<struct node *> path;
  storePath(root,path,x);
  int r = path.size()-1;
  int l = 0;
  int tmp;
  while(l<r){
    tmp = path[l]->data;
    path[l]->data = path[r]->data;
    path[r]->data = tmp;
    l++;
    r--;
  }
  inorder(root);
}
struct node *buildTree(){
  struct node *root = getnode(1);
  root->left = getnode(2);
  root->right = getnode(3);
  root->left->left = getnode(4);
  root->left->right = getnode(5);
  root->right->left = getnode(6);
  root->right->right = getnode(7);
  root->left->left->left = getnode(8);
  root->left->left->right = getnode(9);
  root->left->right->left = getnode(10);
  root->left->right->right = getnode(11);
  root->left->left->right->left = getnode(16);
  root->left->right->right->left = getnode(17);
  root->left->right->right->right = getnode(18);
  root->right->left->left = getnode(12);
  root->right->left->right = getnode(13);
  root->right->right->left = getnode(14);
  root->right->right->right = getnode(15);
  root->right->left->right->right = getnode(19);
  return root;
}
int main(){
    struct node *root = buildTree();
    int x;
    cin>>x;
    reversePath(root,x);
}
