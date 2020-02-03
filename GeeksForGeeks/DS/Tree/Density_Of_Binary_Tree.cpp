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
int max(int a,int b){
  return a>b?a:b;
}
int height(struct node *root){
  if(root==NULL){
    return 0;
  }
  int l_height = height(root->left);
  int r_height = height(root->right);
  return max(l_height,r_height)+1;
}
int countNodes(struct node *root){
  if(root==NULL){
    return 0;
  }
  if(root->left==NULL&&root->right==NULL){
    return 1;
  }
  return 1+countNodes(root->left)+countNodes(root->right);
}
double density(struct node *root){
  int n_nodes = countNodes(root);
  int h_tree = height(root);
  double result = (double)n_nodes/(double)h_tree;
  return result;
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
  cout<<density(root)<<endl;
}
