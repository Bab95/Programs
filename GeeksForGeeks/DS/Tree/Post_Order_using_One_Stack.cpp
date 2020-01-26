#include <iostream>
#include <stack>
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
